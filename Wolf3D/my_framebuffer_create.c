#include "my_framebuffer.h"
#include "my.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  t_my_framebuffer      *buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
  buffer->width = width;
  buffer->height = height;
  return (buffer);
}
