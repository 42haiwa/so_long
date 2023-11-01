NAME := so_long

SRC := src/main.c
OBJ := $(SRC:.c=.o)

CFLAGS := -Wall -Wextra -Werror -Iinclude 
LDFLAGS := -Llib -lmlx42 -lftprintf -ldl -lglfw -pthread -lm

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
