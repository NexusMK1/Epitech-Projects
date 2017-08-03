CFLAGS  +=	-I./include -L./lib/my/ -lmy -L./lib/ -Wextra -Wall -pedantic

LDFLAGS =

SRC	=	my_puterr.c	\
		matches.c	\
		matchsticks.c	\
		turn.c		\
		main.c		\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
