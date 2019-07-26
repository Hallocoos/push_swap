NAME=push_swap.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
SRC=checker.c \push_swap.c \lists.c \push_swap.h
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(OPT) $(SRC) $(LIBSRC)
	@ar rc $(NAME) $(OBJ) $(LIBOBJ) /libft
#	@echo "Compiled libft.a, push_swap.a and *.o files!"

gcc:
	@gcc $(FLAGS) $(SRC) $(LIBSRC)
	@./a.out 1 2 3 4 5 6 7 8 9 0
#	@echo "GCC'd source files!"
so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)
#	@echo "Compiled a.out!"

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o
#	@echo "Removed *.o files!"

fclean: clean
	@/bin/rm -f $(NAME)
#	@echo "Removed libft.a, push_swap.a and *.o files!"

re: fclean all
