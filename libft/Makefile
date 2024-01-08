NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
	ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_split.c ft_substr.c ft_tolower.c ft_toupper.c\
	ft_printf.c ft_put1.c ft_put2.c\
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
	ft_itoa_hex.c ft_digits.c ft_puthex.c ft_putnbr_u.c
OBJ = $(SRCS:.c=.o)

all:	copy $(NAME) clean

copy:
	cp -f bonus/*.c .
	cp -f ft_is/*.c .
	cp -f ft_mem/*.c .
	cp -f ft_other/*.c .
	cp -f printf/*.c .
	cp -f ft_put/*.c .
	cp -f ft_str/*.c .
	cp -f my_fts/*.c .

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	cc $(CFLAGS) -c $(SRCS)

fclean:
	rm -f $(NAME) $(OBJ) $(SRCS)

clean:
	rm -f $(OBJ) $(SRCS)

re: fclean all