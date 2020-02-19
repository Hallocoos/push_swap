NAME=push_swap.a
LIBNAME=libft/libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c
PSHSRC=push_swap.h push_swap.c findfunctions.c lists.c stackfunctions*.c \
stackmanipulation.c libft/libft.a sorting_algorithms*.c
CHKSRC=checker.c lists.c stackfunctions*.c libft/libft.a \
stackmanipulation.c

all: push_swap checker

push_swap:
	gcc $(FLAGS) $(PSHSRC) -o push_swap

checker:
	gcc $(FLAGS) $(CHKSRC) -o checker

so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
