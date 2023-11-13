SRC=push_swap.c \
	stack.c \
	util.c \
	functions.c
OBJ=$(SRC:.c=.o)
HEADERS=push_swap.h
NAME=push_swap
FT=libft/libft.a

all: $(NAME)

%.o: %.c
	cc -c -Wall -Werror -Wextra $< -o $@

$(NAME): $(OBJ) $(FT) $(HEADERS)
	cc -Wall -Werror -Wextra $(FT) $(OBJ) -o $(NAME)

$(FT):
	cd libft && make

clean:
	rm -rf *.o
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd libft && make fclean

re: clean all

.PHONY: all clean fclean re
