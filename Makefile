CC=gcc
NAME=libft.a
FLAGS=-Wall -Werror -Wextra
SRC=checker.c
OBJ=checker.o
OPT=-c

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(OPT) $(SRC)
	@./a.out 1 2 3 4 5 6 7 8 9 0
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "library compiled!"

so:
	@gcc $(OPT) $(FLAGS) $(SRC) cd /libft/*.c
	@gcc -shared -o libft.so -fPIC $(OBJ)
	@rm $(OBJ)

gcc:
	@$(CC) $(FLAGS) $(SRC)
	@rm a.out
	@echo "All .c files compiled"

clean:
	@/bin/rm -f $(OBJ)
	@echo "removed Object files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "removed libft.a"

re: fclean all
