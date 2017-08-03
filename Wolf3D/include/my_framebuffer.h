#ifndef MY_FRAMEBUFFER_H_
#define	MY_FRAMEBUFFER_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define ABS(Value)      ((Value) < (0) ? (-Value) : (Value))

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to, sfColor color);
sfVector2i		my_isometric_projection(sfVector3f pos3d);
sfVector2i		my_parallel_projection(sfVector3f pos3d, float angle);
sfVector2f		move_forward(sfVector2f pos,
				     float direction, float distance);
float			raycast(sfVector2f pos, float direction,
				int **map, sfVector2i mapSize);
void			my_putchar_e(char c);
int			my_puterr(char *str);
#endif
