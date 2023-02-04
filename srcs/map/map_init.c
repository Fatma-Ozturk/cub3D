/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:44 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:46 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	map_fill_cefnsw(t_map *map)
{
	int	i;

	i = -1;
	while (map->grid[++i])
	{
		if (map->grid[i][0] == 'C')
			map->c_val = ft_strdup(map->grid[i]);
		else if (map->grid[i][0] == 'E')
			map->e_path = ft_strdup(map->grid[i]);
		else if (map->grid[i][0] == 'F')
			map->f_val = ft_strdup(map->grid[i]);
		else if (map->grid[i][0] == 'N')
			map->n_path = ft_strdup(map->grid[i]);
		else if (map->grid[i][0] == 'S')
			map->s_path = ft_strdup(map->grid[i]);
		else if (map->grid[i][0] == 'W')
			map->w_path = ft_strdup(map->grid[i]);
	}
	if (map->c_val == NULL || map->f_val == NULL || map->n_path == NULL
		|| map->e_path == NULL || map->s_path == NULL || map->w_path == NULL)
	{
		map->error_msg = "missing path";
		return (-1);
	}
	return (0);
}

static int	rgb_count_control(char **floor, char **ceil)
{
	int	i;

	i = 0;
	while (floor[i] && ceil[i])
		i++;
	if (i != 3)
		return (-1);
	return (0);
}

int	map_rgb(t_map *map)
{
	char	**floor;
	char	**ceil;
	char	*f;
	char	*c;

	f = ft_strtrim(map->f_val, "F ");
	c = ft_strtrim(map->c_val, "C ");
	floor = ft_split(f, ',');
	ceil = ft_split(c, ',');
	if (rgb_count_control(floor, ceil) == -1)
	{
		map->error_msg = "rgb missing count \n";
		return (-1);
	}
	map->c_rgb = create_rgb(ft_atoi(ceil[0]), ft_atoi(ceil[1]),
			ft_atoi(ceil[2]));
	map->f_rgb = create_rgb(ft_atoi(floor[0]), ft_atoi(floor[1]),
			ft_atoi(floor[2]));
	free(f);
	free(c);
	free_double_str(floor);
	free_double_str(ceil);
	return (0);
}

int	map_init(t_map *map, char *av)
{
	map->y = ft_y_size(av);
	map->c_val = NULL;
	map->f_val = NULL;
	map->n_path = NULL;
	map->e_path = NULL;
	map->s_path = NULL;
	map->w_path = NULL;
	map->value_count = 0;
	map_to_arr(map, av);
	map_arr_to_real(map);
	map->grid_y = ft_map_y(map->grid);
	if (map_fill_cefnsw(map) == -1)
		return (-1);
	if (map_rgb(map) == -1)
		return (-1);
	return (0);
}
