/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:28 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:31 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_put_top_charac(t_map *map, int i)
{
	if (i == 0)
		map->grid[0] = ft_strdup(map->c_val);
	else if (i == 1)
		map->grid[1] = ft_strdup(map->e_path);
	else if (i == 2)
		map->grid[2] = ft_strdup(map->f_val);
	else if (i == 3)
		map->grid[3] = ft_strdup(map->n_path);
	else if (i == 4)
		map->grid[4] = ft_strdup(map->s_path);
	else if (i == 5)
		map->grid[5] = ft_strdup(map->w_path);
}

void	map_fix(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_put_top_charac(map, i);
		i++;
	}
}
