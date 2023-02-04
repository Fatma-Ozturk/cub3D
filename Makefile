CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
 
NAME = cub3D
 
SRCS_DIR = ./srcs
SRCS_NAME = main/main.c main/player.c main/init.c \
			raycast/calculate_wall_height.c raycast/draw_wall.c raycast/init_ray.c raycast/ray_out.c raycast/raycast.c raycast/select_texture.c\
			get_next_line/get_next_line.c \
			map/map_fix.c  map/map_init.c map/map_read.c map/map_real.c map/map_init_utils.c\
			check/map_check.c check/map_wall_check.c check/map_ceil_floor_check.c check/map_direction.c check/map_check_utils.c check/map_text_free.c\
			core/core_map.c core/free.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
 
LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)
 
MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)
 
 
$(NAME)	:	$(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
			-framework OpenGL -framework AppKit $^ -o $@
 
$(SRCS_DIR)/%.o	:	$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@
 
 
all:	$(NAME)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re:	fclean all

bonus:	all

.PHONY:	all clean fclean re bonus
