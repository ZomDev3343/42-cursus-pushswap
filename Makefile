SRC=push_swap.c \
	stack.c \
	util.c \
	functions.c \
	test_util.c
OBJ=$(SRC:.c=.o)
HEADERS=push_swap.h
NAME=push_swap
FT=libft/libft.a

all: $(FT) $(NAME)

%.o: %.c
	cc -c -Wall -Werror -Wextra $< -o $@

$(NAME): $(OBJ)
	cc -Wall -Werror -Wextra $(FT) $(OBJ) -o $(NAME)

$(FT):
	cd libft && make

clean:
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(FT)

re: clean all

.PHONY: all clean fclean re libft/libft.a
