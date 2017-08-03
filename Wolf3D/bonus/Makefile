NAME	=	wolf3d

SRC	=	../my_framebuffer_create.c		\
		../src/my_put_pixel.c			\
		../src/my_draw_line.c			\
		../src/move_forward.c			\
		../src/raycast.c			\
		../my_puterr.c				\
		../map_read.c				\
		../position.c				\
		graph.c					\
		../main.c

CFLAGS	+=	-I../include/ -L../lib/my/ -lmy -lm -lc_graph_prog -Wall -Wextra -pedantic

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
