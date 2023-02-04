/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:11 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:55:43 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exit_button(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	loop(t_game *game)
{
	raycast(game);
	return (0);
}

int	map(t_game *game, char **av)
{
	if (map_init(&game->map, av[1]) == -1)
		return (-1);
	if (check_cefnsw(&game->map) == -1)
		return (-1);
	map_fix(&game->map);
	if (map_check(&game->map) == -1)
		return (-1);
	return (0);
}

void	free_all(t_game *game)
{
	free(game->map.error_msg);
	free(game->map.e_path);
	free(game->map.w_path);
	free(game->map.s_path);
	free(game->map.n_path);
	free_double_str(game->map.grid);
	free(game->map.f_val);
	free(game->map.c_val);
	free_double_str(game->map.map_dbl_arr);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && map_name_check(av[1]) == 1)
	{
		if (map(&game, av) == 0)
		{
			init(&game);
			set_player_pos(&game);
			game.map.grid[game.map.player_x][game.map.player_y] = '0';
			mlx_hook(game.win_ptr, KEY_PRESS, 0, key_press, &game);
			mlx_hook(game.win_ptr, KEY_EXIT, 0, exit_button, &game);
			mlx_loop_hook(game.mlx_ptr, loop, &game);
			mlx_loop(game.mlx_ptr);
			free_all(&game);
		}
		else
			printf("error: %s", game.map.error_msg);
	}
	else
		printf("wrong name/path: %s\n", av[1]);
	return (0);
}
