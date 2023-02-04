/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:51 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:57:09 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_to_arr(t_map *map, char *av)
{
	int		i;
	int		fd;
	int		j;
	char	*area;

	write(1, "c\n", 2);
	i = -1;
	j = 0;
	fd = open(av, O_RDONLY);
	map->map_dbl_arr = (char **)malloc(sizeof(char *) * (map->y + 1));
	area = get_next_line(fd);
	while (++i < map->y + 1)
	{
		j = -1;
		if (area == NULL)
			break ;
		map->map_dbl_arr[i] = malloc((sizeof(char) * ft_strlen(area)) + 1);
		while (area[++j] && is_str_space(area) == -1)
			map->map_dbl_arr[i][j] = (char)area[j];
		free(area);
		area = get_next_line(fd);
		map->map_dbl_arr[i][j] = '\0';
	}
	free(area);
	map->map_dbl_arr[i] = 0;
}
