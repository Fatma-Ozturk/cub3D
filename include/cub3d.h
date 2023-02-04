/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:09:08 by faozturk          #+#    #+#             */
/*   Updated: 2023/02/04 11:09:09 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

# define PI 3.14159265359

# define FALSE 0
# define TRUE 1

# define BUFFER_SIZE 1
# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define MOVE_SPEED 0.3
# define ROT_SPEED 0.05

typedef struct s_map
{
	int		x;
	int		y;
	int		grid_y;
	char	**map_dbl_arr;
	char	**grid;
	char	*error_msg;
	char	*e_path;
	char	*n_path;
	char	*w_path;
	char	*s_path;
	char	*c_val;
	char	*f_val;
	int		value_count;
	int		f_rgb;
	int		c_rgb;
	int		player_x;
	int		player_y;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*file;
	int		tex_x;
	int		tex_y;
	int		color;
}				t_img;

typedef struct s_dir
{
	double		x;
	double		y;
}				t_dir;

typedef struct s_player
{
	t_dir		dir;
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_raycast
{
	int			map_x;
	int			map_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_raycast;

typedef struct s_color
{
	int			floor;
	int			ceiling;
}				t_color;

typedef struct s_line
{
	int			height;
	int			start;
	int			end;
}				t_line;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_raycast	raycast;
	t_img		img;
	t_img		texture[4];
	t_color		color;
	t_line		line;
	void		*mlx_ptr;
	void		*win_ptr;
	int			screen_w;
	int			screen_h;
	int			key_code;
	int			moved;
	int			init_success;
	int			x;
	int			y;
}				t_game;

//raycast
void			calculate_wall_height(t_game *game);
void			perp_wall_dist(t_game *game);
void			set_image_data(t_game *game, t_img *temp, t_img *textured);
void			calculate_tex(t_game *game, t_img *textured);
void			wall_x(t_game *game);
void			side_dist(t_game *game);
void			delta_dist(t_game *game);
void			init_ray(t_game *game);
void			ray_out(t_game *game);
void			process(t_game *game, t_img *temp);
void			raycast(t_game *game);
t_img			*select_texture(t_game *game);
//map
int				map_init(t_map *map, char *av);
void			map_to_arr(t_map *map, char *av);
void			map_fix(t_map *map);
void			map_arr_to_real(t_map *map);
int				ft_y_size(char *av);
int				ft_map_y(char **map);
unsigned long	create_rgb(int r, int g, int b);
//check
int				map_check(t_map *map);
int				check_cefnsw(t_map *map);
int				map_zero_check(t_map *map, int i, int j);
int				map_wall_check(t_map *map);
int				map_name_check(char *s);
int				ceilflor_digit(t_map *map, char *ceil, char *flor);
int				ceilflor_range(t_map *map, char *ceil, char *flor);
int				color_count(t_map *map, char *split_c, char *split_f);
int				map_ceilflor_color_check(t_map *map);
int				is_ceilflor(t_map *map, int i);
int				map_player_check(t_map *map);
int				map_texture_right(t_map *map);
int				is_direction(char c);
int				map_character_check(t_map *map);
int				is_geographic(t_map *map, int i);
int				comma_arg(char *ceil, char *floor);
int				comma(char *ceil, char *floor);
int				out_of_range(char **range);
void			ft_text_free(char *pre, char *texture,
					char *path, char *post_path);
int				is_str_space(char *s);
void			free_double_str(char **s);
/* void 			put_map(char **map); */
//get_next_line
char			*ft_strchr(const char *str, int ch);
char			*ft_get_one_line(char *left_str);
char			*ft_new_left_str(char *left_str);
char			*ft_search_n_str(int fd, char *left_str);
char			*get_next_line(int fd);

//player
void			rotate(t_game *game, double rotate);
int				is_wall(t_game *game, int new_map_x, int new_map_y);
int				update_player_a_d(t_game *game, int x, int y);
int				update_player_w_s(t_game *game, int x, int y);
int				key_press(int keycode, t_game *game);

//init
void			init_textures(t_game *game);
void			set_player_pos(t_game *game);
void			init_player(t_game *game);
void			init(t_game *game);

#endif
