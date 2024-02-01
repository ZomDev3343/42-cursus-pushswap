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
	cc -c -Wall -Werror -Wextra -g $< -o $@

$(NAME): $(FT) $(OBJ)
	cc -Wall -Werror -Wextra $(OBJ) $(FT) -o $(NAME)

$(FT):
	make -C libft

bonus: $(CHECKER_OBJ) $(CHECKER)

$(CHECKER): $(CHECKER_OBJ) $(FT)
	cc -Wall -Werror -Wextra $(CHECKER_OBJ) $(FT) -o checker

clean:
	rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)
	make fclean -C libft

re: clean all

.PHONY: all clean fclean re
