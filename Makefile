PNME = push_swap
CNME = checker
LIB = libft/libft.a
MAKELIB = -C libft
FLAGS=-Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -g
PSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c libft/*.c sorting_algorithms*.c push_swap.c
CSRC=push_swap.h lists.c stackfunctions*.c algo_helpers*.c findfunctions.c \
stackmanipulation.c libft/*.c sorting_algorithms*.c checker.c

all: $(MAKELIB) $(CNME) $(PNME)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)

$(CNME):
	gcc $(FLGS) $(CSRC) -o $(CNME)

$(PNME):
	gcc $(FLGS) $(PSRC) -o $(PNME)

ps:
	gcc $(FLGS) $(CSRC) -o $(CNME)
	gcc $(FLGS) $(PSRC) -o $(PNME)

db:
	gcc $(DBFLG) $(CSRC) -ggdb3 -o $(CNME)
	gcc $(DBFLG) $(PSRC) -ggdb3 -o $(PNME)

clean:
	rm -fr $(CNME) $(PNME) $(CNME).dSYM $(PNME).dSYM
	rm -f libft/*.o

fclean: clean
	rm -f libft/*.o libft/libft.a

re: clean all

redb: clean db