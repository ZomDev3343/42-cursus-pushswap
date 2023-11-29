SRC=push_swap.c \
	sort_utils.c \
	sort.c \
	check_params.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	stack.c \
	stack2.c \
	utils.c
OBJ=$(SRC:.c=.o)
HEADERS=push_swap.h
NAME=push_swap
FT=libft/libft.a

all: $(NAME)

%.o: %.c
	cc -c -Wall -Werror -Wextra $< -o $@

$(NAME): $(FT) $(OBJ)
	cc -Wall -Werror -Wextra $(FT) $(OBJ) -o $(NAME)

$(FT):
	make -C libft

clean:
	rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: clean all

.PHONY: all clean fclean re libft/libft.a
