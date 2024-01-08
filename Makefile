SRC=push_swap.c \
	sort_utils.c \
	sort.c \
	sort2.c \
	check_params.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	stack.c \
	stack2.c \
	utils.c
CHECKER_SRC=bonus/checker.c \
	sort_utils.c \
	check_params.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	stack.c \
	stack2.c \
	utils.c
CHECKER_OBJ=$(CHECKER_SRC:.c=.o)
OBJ=$(SRC:.c=.o)
HEADERS=push_swap.h
NAME=push_swap
CHECKER=checker
FT=libft/libft.a

all: $(NAME)

%.o: %.c
	cc -c -Wall -Werror -Wextra $< -o $@

$(NAME): $(FT) $(OBJ)
	cc -Wall -Werror -Wextra $(FT) $(OBJ) -o $(NAME)

$(FT):
	make -C libft

bonus: $(CHECKER_OBJ) $(FT)
	cc -Wall -Werror -Wextra $(FT) $(CHECKER_OBJ) -o checker

clean:
	rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)
	make fclean -C libft

re: clean all

.PHONY: all clean fclean re
