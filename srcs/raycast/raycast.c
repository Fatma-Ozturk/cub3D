/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:13:33 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:13:35 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	process(t_game *game, t_img *temp)
{
	t_img	*textured;

	init_ray(game);
	delta_dist(game);
	side_dist(game);
	ray_out(game);
	perp_wall_dist(game);
	calculate_wall_height(game);
	textured = select_texture(game);
	wall_x(game);
	calculate_tex(game, textured);
	set_image_data(game, temp, textured);
}

void	raycast(t_game *game)
{
	t_img	temp;

	temp.bpp = 0;
	temp.size_line = 0;
	temp.endian = 0;
	game->x = -1;
	temp.img = mlx_new_image(game->mlx_ptr, game->screen_w, game->screen_h);
	temp.data = (int *)mlx_get_data_addr(temp.img, &temp.bpp,
			&temp.size_line, &temp.endian);
	while (++game->x < game->screen_w)
		process(game, &temp);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, temp.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, temp.img);
}
