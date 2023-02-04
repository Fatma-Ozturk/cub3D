/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:13:14 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:16 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_image_data(t_game *game, t_img *temp, t_img *textured)
{
	int			y;
	long int	color;

	y = -1;
	while (++y < game->screen_h)
	{
		if (y < game->line.start)
			temp->data[y * game->screen_w + game->x] = game->color.ceiling;
		else if (y >= game->line.start && y <= game->line.end)
		{
			game->raycast.tex_y = (int)game->raycast.tex_pos
				& (textured->height - 1);
			game->raycast.tex_pos += game->raycast.step;
			color = textured->data[game->raycast.tex_y
				* textured->height + game->raycast.tex_x];
			temp->data[y * game->screen_w + game->x] = color;
		}
		else if (y < game->screen_h)
			temp->data[y * game->screen_w + game->x] = game->color.floor;
	}
}

void	calculate_tex(t_game *game, t_img *textured)
{
	game->raycast.tex_x = (int)(game->raycast.wall_x * (double)textured->width);
	if (game->raycast.side == 0 && game->raycast.raydir_x > 0)
		game->raycast.tex_x = textured->width - game->raycast.tex_x - 1;
	if (game->raycast.side == 1 && game->raycast.raydir_y < 0)
		game->raycast.tex_x = textured->width - game->raycast.tex_x - 1;
	game->raycast.step = 1.0 * (double)textured->height
		/ (double)game->line.height;
	game->raycast.tex_pos = (double)(game->line.start - game->screen_h / 2
			+ game->line.height / 2) * game->raycast.step;
}

void	wall_x(t_game *game)
{
	if (game->raycast.side == 0)
		game->raycast.wall_x = game->player.pos_y + game->raycast.perp_wall_dist
			* game->raycast.raydir_y;
	else
		game->raycast.wall_x = game->player.pos_x + game->raycast.perp_wall_dist
			* game->raycast.raydir_x;
	game->raycast.wall_x -= floor(game->raycast.wall_x);
}
