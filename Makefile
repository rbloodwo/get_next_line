
NAME 		= gnl
FLAGS 		= -Wall -Werror -Wextra
SRC			= gnlV2.c

OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@cp libft/libft.a ./
	@gcc $(FLAGS) $(OBJ) -o $(NAME) libft.a
	@make clean

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) -I .

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make -C libft/ fclean

re: fclean all