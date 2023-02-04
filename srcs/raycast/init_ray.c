/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:13:20 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:22 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	side_dist(t_game *game)
{
	if (game->raycast.raydir_x < 0)
	{
		game->raycast.step_x = -1;
		game->raycast.side_dist_x = (game->player.pos_x - game->raycast.map_x)
			* game->raycast.delta_dist_x;
	}
	else if (game->raycast.raydir_x >= 0)
	{
		game->raycast.step_x = 1;
		game->raycast.side_dist_x = (game->raycast.map_x + 1.0
				- game->player.pos_x) * game->raycast.delta_dist_x;
	}
	if (game->raycast.raydir_y < 0)
	{
		game->raycast.step_y = -1;
		game->raycast.side_dist_y = (game->player.pos_y - game->raycast.map_y)
			* game->raycast.delta_dist_y;
	}	
	else if (game->raycast.raydir_y >= 0)
	{
		game->raycast.step_y = 1;
		game->raycast.side_dist_y = (game->raycast.map_y + 1.0
				- game->player.pos_y) * game->raycast.delta_dist_y;
	}
}

void	delta_dist(t_game *game)
{
	if (game->raycast.raydir_y == 0)
		game->raycast.delta_dist_x = 0;
	else
	{
		if (game->raycast.raydir_x == 0)
			game->raycast.delta_dist_x = 1;
		else
			game->raycast.delta_dist_x = fabs(1 / game->raycast.raydir_x);
	}
	if (game->raycast.raydir_x == 0)
		game->raycast.delta_dist_y = 0;
	else
	{
		if (game->raycast.raydir_y == 0)
			game->raycast.delta_dist_y = 1;
		else
			game->raycast.delta_dist_y = fabs(1 / game->raycast.raydir_y);
	}
}

void	init_ray(t_game *game)
{
	game->raycast.camera_x = (2 * game->x / (double)game->screen_w) - 1;
	game->raycast.raydir_x = game->player.dir.x
		+ game->player.plane_x * game->raycast.camera_x;
	game->raycast.raydir_y = game->player.dir.y
		+ game->player.plane_y * game->raycast.camera_x;
	game->raycast.map_x = (int)game->player.pos_x;
	game->raycast.map_y = (int)game->player.pos_y;
}
