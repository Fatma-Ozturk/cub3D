/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:37 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:39 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_y_size(char *av)
{
	int		fd;
	int		count;
	int		byte;
	char	buf;

	fd = 0;
	count = 0;
	buf = 0;
	byte = 1;
	fd = open(av, O_RDONLY);
	while (byte > 0)
	{
		byte = read(fd, &buf, 1);
		if (buf == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	ft_map_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
