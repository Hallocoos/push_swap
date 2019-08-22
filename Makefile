NAME=push_swap.a
LIBNAME=libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
SRC=*.c \ *.h
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c

all: $(NAME)

gcc: $(NAME)

#$(NAME): push_swap.a
#	@gcc $(FLAGS) $(SRC) $(LIBNAME)
#	@ar rc $(NAME) $(OBJ) $(LIBOBJ)

push_swap.a:
	gcc $(FLAGS) lists.c push_swap.h checker.c stackfunctions1.c stackfunctions2.c stackfunctions3.c libft/*.c
so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
