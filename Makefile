NAME = so_long

CFLAGS = -Wall -Wextra -Werror
MAIN = game/main.c
SRCS = game/get_map.c game/game.c game/images.c game/walk.c\
		map_check/check_map.c map_check/floodfill.c map_check/path_check.c
BONUS = bonus/main_bonus.c bonus/map_bonus.c bonus/game_bonus.c\
		bonus/images_bonus.c bonus/walk_bonus.c bonus/enemy_bonus.c

MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a -ldl -lglfw -pthread -lm
GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): lib $(SRCS) $(MAIN)
	cc $(CFLAGS) $(SRCS) $(MAIN) $(GNL) $(LIBFT) $(MLX) -o $(NAME)

lib:
	make -sC $(GNL_PATH)
	make -sC $(LIBFT_PATH)

bonus: lib $(BONUS) $(SRCS)
	cc $(CFLAGS) $(BONUS) $(SRCS) $(GNL) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -sC $(GNL_PATH)
	make clean -sC $(LIBFT_PATH)

fclean:
	rm -f $(NAME)
	make fclean -sC $(GNL_PATH)
	make fclean -sC $(LIBFT_PATH)

re: fclean all
