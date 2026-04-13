NAME = push_swap

SRC = main.c parsing.c parsing_utils.c init_stack.c sort.c sort_small.c sort_big.c \
	  ops_swap.c ops_push.c ops_rotate.c ops_revrotate.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
