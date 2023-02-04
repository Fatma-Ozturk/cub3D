/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:44 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:11:06 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_geographic(t_map *map, int i)
{
	char	*frst;

	frst = ft_substr(map->grid[i], 0, 3);
	if (ft_strncmp(frst, "EA ", 3) == 0 || ft_strncmp(frst, "NO ", 3) == 0
		|| ft_strncmp(frst, "SO ", 3) == 0 || ft_strncmp(frst, "WE ", 3) == 0
		|| frst[2] == 32)
	{
		free(frst);
		return (0);
	}
	map->error_msg = "wrong geographic";
	free(frst);
	return (-1);
}

int	map_character_check(t_map *map)
{
	int	i;
	int	j;

	i = map->value_count;
	j = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (is_direction(map->grid[i][j]) == -1)
			{
				map->error_msg = "invalid character";
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_direction(char c)
{
	char	*ar;

	ar = ft_strdup("WENS");
	if (ft_strchr(ar, c) != 0 || (c == '1' || c == '0'
			|| c == 32 || c == '\n'))
	{
		free(ar);
		return (0);
	}
	free(ar);
	return (-1);
}

int	map_texture_right(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i] && map->grid[i][0] > 32)
	{
		if (ft_strchr("ENSW", map->grid[i][0]) != 0)
		{
			if (is_geographic(map, i) == -1)
				return (-1);
			map->value_count++;
		}
		else if (ft_strchr("CF", map->grid[i][0]) != 0)
		{
			if (is_ceilflor(map, i) == -1)
			{
				return (-1);
			}
			map->value_count++;
		}
	i++;
	}
	return (0);
}

int	map_player_check(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 6;
	player = 0;
	while (map->grid[i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (ft_strchr("WSNE", map->grid[i][j]) != 0)
			{
				map->player_x = i;
				map->player_y = j;
				player++;
			}
		}
		i++;
	}
	if (player == 1)
		return (0);
	map->error_msg = "Player count is wrong";
	return (-1);
}
