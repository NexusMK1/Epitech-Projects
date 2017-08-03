#include "my_framebuffer.h"
#include "my.h"

sfVector2i	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i	projection;

  projection.x = (pos3d.x - pos3d.z) / sqrt(2);
  projection.y = (pos3d.x + 2 * pos3d.y + pos3d.z) / sqrt(6);
  return (projection);
}
