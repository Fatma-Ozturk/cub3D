/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_real.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:58 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:00 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	grid_size(t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map->map_dbl_arr[i])
	{
		if (is_str_space(map->map_dbl_arr[i]) == -1)
			count++;
		i++;
	}
	return (count);
}

void	map_arr_to_real(t_map *map)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = grid_size(map);
	map->grid = (char **)malloc(sizeof(char *) * size + 1);
	while (map->map_dbl_arr[i])
	{
		if (is_str_space(map->map_dbl_arr[i]) == -1)
		{
			map->grid[j] = map->map_dbl_arr[i];
			j++;
		}
		i++;
	}
	map->grid[j] = 0;
}
