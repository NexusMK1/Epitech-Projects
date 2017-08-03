CFLAGS  +=	-I./include -L./lib/my/ -lmy -lncurses -Wextra -Wall -pedantic -Werror

LDFLAGS =

SRC	=	my_puterr.c		\
		my_strmemcat.c		\
		manual.c		\
		sokoban.c		\
		position.c		\
		movements.c		\
		victory_conditions.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
