NAME=push_swap.a
LIBNAME=libft/libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC=$(shell find libft/ -name "*.c")
CHKSRC=checker.c push_swap.h stackfunctions*.c lists.c
PSHSRC=push_swap.c push_swap.h stackmanipulation.c \
stackfunctions*.c lists.c findfunctions.c
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c

all: $(NAME)

gcc: $(NAME)

ps:
	gcc push_swap.c push_swap.h findfunctions.c lists.c	stackfunctions*.c \
		stackmanipulation.c libft/libft.a	

checker:
	gcc checker.c push_swap.h lists.c stackfunctions*.c libft/libft.a \
		stackmanipulation.c

so:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(LIBSRC)
	@gcc -shared -o libft.so -fPIC $(OBJ) $(LIBOBJ)
	@rm $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ) *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
