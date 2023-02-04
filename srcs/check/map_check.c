/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:38 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:54:16 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_name_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] && s[i] != '.')
		i--;
	i++;
	if (open(s, O_RDONLY) == -1)
		return (-1);
	if (ft_strnstr("cub", &s[i], 3) && s[i + 3] == '\0')
		return (1);
	return (0);
}

static int	ft_texture_check(char *texture)
{
	int		fd;
	char	*path;
	char	*pre;
	char	*post_path;

	fd = 0;
	pre = ft_substr(texture, 0, 3);
	texture = ft_strtrim(texture, pre);
	path = ft_strjoin("./images/", texture);
	post_path = ft_strtrim(path, "\n");
	fd = open(post_path, O_RDWR, 777);
	if (fd == -1)
	{
		ft_text_free(pre, texture, path, post_path);
		return (-1);
	}	
	else
	{
		ft_text_free(pre, texture, path, post_path);
		close(fd);
		return (1);
	}
}

static int	map_texture_path(t_map *map)
{
	if (ft_texture_check(map->e_path) == -1
		|| ft_texture_check(map->n_path) == -1
		|| ft_texture_check(map->s_path) == -1
		|| ft_texture_check(map->w_path) == -1)
	{
		map->error_msg = "texture path invalid";
		return (-1);
	}
	return (0);
}

int	map_check(t_map *map)
{
	if (map_texture_right(map) == -1)
		return (-1);
	if (map_wall_check(map) == -1)
		return (-1);
	if (map_character_check(map) == -1)
		return (-1);
	if (map_player_check(map) == -1)
		return (-1);
	if (map_ceilflor_color_check(map) == -1)
		return (-1);
	if (map_texture_path(map) == -1)
		return (-1);
	if (map->value_count != 6)
	{
		map->error_msg = "wrong path count";
		return (-1);
	}
	return (1);
}
