CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SRC = push_swap.c sort_stacks.c sort35_utils.c push.c rev_rotate.c rotate.c swap.c \
ft_printf.c split.c \
errors.c init_a2b.c init_b2a.c stack_init.c \

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all