/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:13:39 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:41 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_img	*select_texture(t_game *game)
{
	if (game->raycast.side == 1)
	{
		if ((game->raycast.raydir_x <= 0 && game->raycast.raydir_y <= 0)
			|| (game->raycast.raydir_x >= 0 && game->raycast.raydir_y <= 0))
			return (&game->texture[0]);
		else
			return (&game->texture[1]);
	}
	else
	{
		if ((game->raycast.raydir_x <= 0 && game->raycast.raydir_y <= 0)
			|| (game->raycast.raydir_x <= 0 && game->raycast.raydir_y >= 0))
			return (&game->texture[2]);
		else
			return (&game->texture[3]);
	}
	return (NULL);
}
