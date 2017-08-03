#include "../include/my_framebuffer.h"

void	check_pixel(t_my_framebuffer *framebuffer,
		    int x, int y, sfColor color)
{
  if (x > 0 && y > 0
      && x < framebuffer->width && y < framebuffer->height)
    my_put_pixel(framebuffer, x, y, color);
}

void	my_draw_line(t_my_framebuffer *framebuffer,
		     sfVector2i from, sfVector2i to, sfColor color)
{
  float		a;
  float		vx;
  float		vy;
  sfVector2f	crd;

  crd.x = from.x;
  crd.y = from.y;
  vx = to.x - from.x;
  vy = to.y - from.y;
  a = ABS(vx) + ABS(vy);
  vx = vx / a;
  vy = vy / a;
      check_pixel(framebuffer, (int)crd.x, (int)crd.y, color);
      while ((int)crd.x != to.x || (int)crd.y != to.y)
	{
	  check_pixel(framebuffer, (int)crd.x, (int)crd.y, color);
	  if ((int)crd.x != to.x)
	    crd.x = crd.x + vx;
	  if ((int)crd.y != to.y)
	    crd.y = crd.y + vy;
	}
      check_pixel(framebuffer, (int)crd.x, (int)crd.y, color);
}
