SRC=push_swap.c \
	sort_utils.c \
	check_params.c
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
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(FT)

re: clean all

.PHONY: all clean fclean re
