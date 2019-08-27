NAME=libft.a
FLAGS=-Wall -Werror -Wextra
SRC=*.c 
OBJ=*.o
OPT=-c


all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(OPT) $(SRC) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiled libft.a!"

so:
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@gcc -shared -o libft.so -fPIC $(OBJ)
	@rm $(OBJ)
	@echo "Compiled a.out!"

clean:
	@/bin/rm -f $(OBJ)
	@echo "Removed *.o files!"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Removed libft.a file!"

re: fclean all
