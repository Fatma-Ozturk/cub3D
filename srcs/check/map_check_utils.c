/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:32 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:11:15 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	out_of_range(char **range)
{
	int	r_0;
	int	r_1;
	int	r_2;

	r_0 = ft_atoi(range[0]);
	r_1 = ft_atoi(range[1]);
	r_2 = ft_atoi(range[2]);
	if ((r_0 < 0 || r_0 > 255) || (r_1 < 0 || r_1 > 255)
		|| (r_2 < 0 || r_2 > 255))
		return (-1);
	return (0);
}

int	comma(char *ceil, char *floor)
{
	int	c;
	int	f;
	int	c_com;
	int	f_com;

	c_com = 0;
	f_com = 0;
	c = -1;
	f = -1;
	while (ceil[++c])
	{
		if (ceil[c] == ',')
			c_com++;
	}
	while (floor[++f])
	{
		if (floor[f] == ',')
			f_com++;
	}
	if (c_com != 2 || f_com != 2)
		return (-1);
	return (0);
}

int	comma_arg(char *ceil, char *floor)
{
	int	c;
	int	f;

	c = -1;
	f = -1;
	while (ceil[++c] && floor[++f])
	{
		if (ceil[c] == ',' && !ft_isdigit(ceil[c + 1]))
			return (-1);
		else if (floor[f] == ',' && !ft_isdigit(floor[f + 1]))
			return (-1);
	}
	return (0);
}

int	check_cefnsw(t_map *map)
{
	if (!ft_strlen(map->c_val) || !ft_strlen(map->e_path)
		|| !ft_strlen(map->f_val) || !ft_strlen(map->n_path)
		|| !ft_strlen(map->s_path) || !ft_strlen(map->w_path))
		return (-1);
	return (1);
}
