#include "../include/my_framebuffer.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x = pos.x + (distance * cos(direction * M_PI / 180));
  pos.y = pos.y + (distance * sin(direction * M_PI / 180));
  return (pos);
}
