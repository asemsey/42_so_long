NAME = so_long

CFLAGS = -Wall -Wextra -Werror
SRCS = test.c check_map.c floodfill.c path_check.c

GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): lib $(SRCS)
	cc $(CFLAGS) $(SRCS) $(GNL) $(LIBFT) -o $(NAME)

lib:
	make -sC $(GNL_PATH)
	make -sC $(LIBFT_PATH)

# clean:

fclean:
	rm -f $(NAME)
	make fclean -sC $(GNL_PATH)
	make fclean -sC $(LIBFT_PATH)

re: fclean all
