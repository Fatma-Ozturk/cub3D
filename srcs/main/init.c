/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:03 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:06 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture_img_data(t_game *game, int i, char *wesn)
{
	char	*sub;
	char	*pre_trim;
	char	*post_trim;
	char	*join;

	sub = ft_substr(wesn, 0, 5);
	pre_trim = ft_strtrim(wesn, sub);
	post_trim = ft_strtrim(pre_trim, "\n");
	join = ft_strjoin("./images/", post_trim);
	game->texture[i].img = mlx_xpm_file_to_image(game->mlx_ptr, join,
			&(game->texture[i].width), &(game->texture[i].height));
	game->texture[i].data = (int *)mlx_get_data_addr(game->texture[i].img,
			&(game->texture[i].bpp), &(game->texture[i].size_line),
			&(game->texture[i].endian));
	free(sub);
	free(pre_trim);
	free(post_trim);
	free(join);
}

void	init_textures(t_game *game)
{
	init_texture_img_data(game, 0, game->map.e_path);
	init_texture_img_data(game, 1, game->map.w_path);
	init_texture_img_data(game, 2, game->map.s_path);
	init_texture_img_data(game, 3, game->map.n_path);
}

void	set_player_pos(t_game *game)
{
	int		row;
	int		col;
	char	map_factor;

	row = 5;
	while (game->map.grid[++row])
	{
		col = -1;
		while (game->map.grid[row][++col])
		{
			map_factor = game->map.grid[row][col];
			if (map_factor == 'S')
				rotate(game, M_PI);
			else if (map_factor == 'W')
				rotate(game, 1.5 * M_PI);
			else if (map_factor == 'E')
				rotate(game, 0.5 * M_PI);
			else if (map_factor == 'N')
				rotate(game, 0);
		}
	}
}

void	init_player(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->move_speed = MOVE_SPEED;
	player->rot_speed = ROT_SPEED;
	player->pos_x = game->map.player_x + 0.5;
	player->pos_y = game->map.player_y + 0.5;
}

void	init(t_game *game)
{
	init_player(game);
	game->screen_w = 1080;
	game->screen_h = 720;
	game->color.floor = game->map.f_rgb;
	game->color.ceiling = game->map.c_rgb;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->screen_w, game->screen_h, "cub3D");
	init_textures(game);
}
