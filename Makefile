NAME=push_swap.a
LIBNAME=libft/libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c
PSHSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c libft/*.c sorting_algorithms*.c push_swap.c
CHKSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c libft/*.c sorting_algorithms*.c checker.c

all: push_swap checker

push_swap:
	gcc $(FLAGS) $(PSHSRC) -ggdb3 -o push_swap

checker:
	gcc $(FLAGS) $(CHKSRC) -ggdb3 -o checker

so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: clean all
