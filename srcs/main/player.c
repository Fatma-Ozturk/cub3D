/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:19 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:12:21 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate(t_game *game, double rotate)
{
	double	tmp_p_x;
	double	tmp_dir_x;

	tmp_dir_x = game->player.dir.x;
	tmp_p_x = game->player.plane_x;
	game->player.dir.x = tmp_dir_x * cos(-rotate)
		- game->player.dir.y * sin(-rotate);
	game->player.dir.y = tmp_dir_x * sin(-rotate)
		+ game->player.dir.y * cos(-rotate);
	game->player.plane_x = tmp_p_x * cos(-rotate)
		- game->player.plane_y * sin(-rotate);
	game->player.plane_y = tmp_p_x * sin(-rotate)
		+ game->player.plane_y * cos(-rotate);
}

int	is_wall(t_game *game, int new_map_x, int new_map_y)
{
	if (game->map.grid[(int)game->player.pos_x][new_map_y] != '0' &&
			game->map.grid[new_map_x][(int)game->player.pos_y] != '0')
		return (TRUE);
	if (game->map.grid[new_map_x][new_map_y] != '0')
		return (TRUE);
	return (FALSE);
}

int	update_player_a_d(t_game *game, int x, int y)
{
	double	temp_x;
	double	temp_y;

	temp_x = game->player.pos_x + x * game->player.dir.y
		* game->player.move_speed;
	temp_y = game->player.pos_y + y * game->player.dir.x
		* game->player.move_speed;
	if (is_wall(game, (int)(temp_x), (int)(temp_y)))
		return (-1);
	else
	{
		game->player.pos_x = temp_x;
		game->player.pos_y = temp_y;
	}
	return (0);
}

int	update_player_w_s(t_game *game, int x, int y)
{
	double	temp_x;
	double	temp_y;

	temp_x = game->player.pos_x + x
		* game->player.dir.x * game->player.move_speed;
	temp_y = game->player.pos_y + y
		* game->player.dir.y * game->player.move_speed;
	if (is_wall(game, (int)(temp_x), (int)(temp_y)))
		return (-1);
	else
	{
		game->player.pos_x = temp_x;
		game->player.pos_y = temp_y;
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT)
		rotate(game, -ROT_SPEED);
	if (keycode == KEY_RIGHT)
		rotate(game, ROT_SPEED);
	if (keycode == KEY_A)
		update_player_a_d(game, -1, 1);
	if (keycode == KEY_D)
		update_player_a_d(game, 1, -1);
	if (keycode == KEY_W)
		update_player_w_s(game, 1, 1);
	if (keycode == KEY_S)
		update_player_w_s(game, -1, -1);
	return (0);
}
