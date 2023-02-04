/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:13:08 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:10 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_wall_height(t_game *game)
{
	game->line.height = (int)(game->screen_h / game->raycast.perp_wall_dist);
	game->line.start = (-1 * game->line.height / 2) + (game->screen_h / 2);
	if (game->line.start < 0)
		game->line.start = 0;
	game->line.end = (game->line.height) / 2 + (game->screen_h / 2);
	if (game->line.end >= game->screen_h)
		game->line.end = game->screen_h - 1;
}

void	perp_wall_dist(t_game *game)
{
	if (game->raycast.side == 0)
		game->raycast.perp_wall_dist = (game->raycast.map_x - game->player.pos_x
				+ (1 - game->raycast.step_x) / 2) / game->raycast.raydir_x;
	else
		game->raycast.perp_wall_dist = (game->raycast.map_y - game->player.pos_y
				+ (1 - game->raycast.step_y) / 2) / game->raycast.raydir_y;
}
