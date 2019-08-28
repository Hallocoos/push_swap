NAME=push_swap.a
LIBNAME=libft/libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
SRC=*.c *.h
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c

all: checker

push_swap: checker

checker:
	gcc $(FLAGS) $(SRC) $(LIBNAME)

so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
