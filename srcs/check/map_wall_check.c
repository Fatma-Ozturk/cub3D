/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:55 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:10:58 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static int	reverse_check(t_map *map, int i, int j)
{
	if (map->grid[i][j + 1] == '1' || map->grid[i][j + 1] == '0')
		return (1);
	else if (map->grid[i][j - 1] == '1' || map->grid[i][j - 1] == '0' )
		return (1);
	else if (map->grid[i + 1][j] == '1' || map->grid[i + 1][j] == '0')
		return (1);
	else if (map->grid[i - 1][j] == '1' || map->grid[i - 1][j] == '0')
		return (1);
	return (-1);
}

int	map_zero_check(t_map *map, int i, int j)
{
	if (map->grid[i][j + 1] <= 32)
		return (-1);
	if (map->grid[i][j - 1] <= 32)
		return (-1);
	if (map->grid[i + 1][j] <= 32)
		return (-1);
	if (map->grid[i - 1][j] <= 32)
		return (-1);
	if (reverse_check(map, i, j) == 1)
		return (1);
	if (ft_strlen(map->grid[i - 1]) < ft_strlen(map->grid[i]))
		return (-1);
	return (1);
}

int	map_wall_check(t_map *map)
{
	int	i;
	int	j;

	i = map->value_count;
	while (map->grid[i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == '0')
			{
				if (j == 0 || i == map->grid_y - 1
					|| map_zero_check(map, i, j) == -1 || i == map->value_count)
				{
					map->error_msg = "Wall problem";
					return (-1);
				}
			}
		}
		i++;
	}
	return (1);
}
