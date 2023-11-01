NAME := so_long

SRC := src/main.c \
		src/map_checker.c \
		src/map_checker2.c \
		src/map_parser.c \
		src/hook_manager.c
OBJ := $(SRC:.c=.o)

CFLAGS := -g -Wall -Wextra -Werror -Iinclude -I/usr/include -Iinclude/mlx_linux
LDFLAGS := -Llib -lftprintf -lgnl -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Iinclude/mlx_linux -ldl -pthread -lXext -lX11 -lm -lz

.PHONY: all clean fclean re

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all
