NAME=push_swap
LIBNAME=libft/libft.a
FLAGS=-Wall -Werror -Wextra
LIBSRC= libft/ft_strsplit.c \
libft/ft_putstr.c \
libft/ft_strchr.c \
libft/ft_putnbr.c \
libft/ft_atoi.c \
libft/ft_itoa.c \
libft/ft_strequ.c \
libft/ft_isdigit.c \
libft/ft_wordcount.c \
libft/ft_wordlen.c \
libft/ft_arrlen.c \
libft/ft_strnew.c \
libft/ft_putchar.c \
libft/ft_strlen.c \
libft/ft_convert.c \
libft/ft_strdup.c \
libft/ft_memcpy.c \
libft/get_next_line.c \
libft/ft_len.c \
libft/ft_lstnew.c \
libft/ft_lstadd.c \
libft/ft_strndup.c \
libft/ft_strjoin.c \
libft/ft_memset.c \
libft/ft_bzero.c \
libft/ft_strclr.c
LIBOBJ=$(shell find libft/ -name "*.o")
OBJ=checker.o \push_swap.o \lists.o
OPT=-c
PSHSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c $(LIBSRC) sorting_algorithms*.c push_swap.c
CHKSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c $(LIBSRC) sorting_algorithms*.c checker.c

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
	@/bin/rm -f $(NAME) checker

re: fclean all
