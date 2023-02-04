/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ceil_floor_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:25 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:17:51 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_ceilflor(t_map *map, int i)
{
	char	*frst;

	frst = ft_substr(map->grid[i], 0, 2);
	if (ft_strncmp(frst, "F ", 2) == 0 || ft_strncmp(frst, "C ", 2) == 0
		|| frst[1] == 32)
	{
		free(frst);
		return (0);
	}
	map->error_msg = "wrong ceil/floor";
	free(frst);
	return (-1);
}

int	map_ceilflor_color_check(t_map *map)
{
	char	**splitc;
	char	**splitf;

	splitc = ft_split(map->c_val, ' ');
	splitf = ft_split(map->f_val, ' ');
	if (ceilflor_digit(map, splitc[1], splitf[1]) == -1
		|| color_count(map, splitc[1], splitf[1]) == -1)
	{
		free_double_str(splitc);
		free_double_str(splitf);
		return (-1);
	}
	else if (ceilflor_range(map, splitc[1], splitf[1]) == -1)
	{
		free_double_str(splitc);
		free_double_str(splitf);
		return (-1);
	}
	free_double_str(splitc);
	free_double_str(splitf);
	return (0);
}

int	color_count(t_map *map, char *split_c, char *split_f)
{
	if (comma(split_c, split_f) == -1)
	{
		map->error_msg = "C/F missing color";
		return (-1);
	}
	else if (comma_arg(split_c, split_f) == -1)
	{
		map->error_msg = "C/F missing color";
		return (-1);
	}
	return (0);
}

int	ceilflor_range(t_map *map, char *ceil, char *flor)
{
	char	**ceil_range;
	char	**flor_range;

	ceil_range = ft_split(ceil, ',');
	flor_range = ft_split(flor, ',');
	if (out_of_range(ceil_range) == -1 || out_of_range(flor_range) == -1)
	{
		free_double_str(ceil_range);
		free_double_str(flor_range);
		map->error_msg = "C/F color out of range";
		return (-1);
	}
	free_double_str(ceil_range);
	free_double_str(flor_range);
	return (0);
}

int	ceilflor_digit(t_map *map, char *ceil, char *flor)
{
	int	i;

	i = -1;
	while (ceil[++i] && ceil[i] != '\n')
	{
		if (ft_isdigit(ceil[i]) == 0 && ceil[i] != ',' && ceil[i] != '-')
		{
			map->error_msg = "C/F is not digit";
			return (-1);
		}
	}
	i = -1;
	while (flor[++i] && flor[i] != '\n')
	{
		if (ft_isdigit(flor[i]) == 0 && flor[i] != ',' && ceil[i] != '-')
		{
			map->error_msg = "C/F is not digit";
			return (-1);
		}
	}
	return (0);
}
