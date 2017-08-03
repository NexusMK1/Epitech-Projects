#include "../include/my_framebuffer.h"

void                    my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color)
{
  if (x >= 0 && y >= 0
      && x <= framebuffer->width && y <= framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
