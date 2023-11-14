NAME := so_long

SRC := src/main.c \
		src/map_checker.c \
		src/map_checker2.c \
		src/map_parser.c \
		src/utils.c \
		src/player_utils.c \
		src/player.c \
		src/map_renderer.c \
		src/alloc_image_tex.c \
		src/bfs.c \
		src/map_exitable.c
OBJ := $(SRC:.c=.o)

CFLAGS := -g -Wall -Wextra -Werror -Iinclude
LDFLAGS := -Llib -lmlx42 -lftprintf -lgnl -ldl -lglfw -pthread -lm

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
