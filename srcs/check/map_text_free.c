/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_text_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:10:49 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:11:03 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_text_free(char *pre, char *texture, char *path, char *post_path)
{
	free(pre);
	free(texture);
	free(path);
	free(post_path);
}
