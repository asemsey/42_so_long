NAME = so_long

CFLAGS = -Wall -Wextra -Werror
SRCS = game/start.c game/game.c game/images.c game/walk.c\
		map_check/check_map.c map_check/floodfill.c map_check/path_check.c

MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a -ldl -lglfw -pthread -lm
GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): lib $(SRCS)
	cc $(CFLAGS) $(SRCS) $(GNL) $(LIBFT) $(MLX) -o $(NAME)

lib:
	make -sC $(GNL_PATH)
	make -sC $(LIBFT_PATH)

clean:
	make clean -sC $(GNL_PATH)
	make clean -sC $(LIBFT_PATH)

fclean:
	rm -f $(NAME)
	make fclean -sC $(GNL_PATH)
	make fclean -sC $(LIBFT_PATH)

re: fclean all
