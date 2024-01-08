# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 16:58:11 by asemsey           #+#    #+#              #
#    Updated: 2024/01/07 19:05:24 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

fclean:
	rm -f $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

re: fclean all