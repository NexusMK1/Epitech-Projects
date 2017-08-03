#include "my_framebuffer.h"
#include "my.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i	projection;

  projection.x = ((pos3d.x * cos(angle * M_PI / 180))
		  - (pos3d.y * sin(angle * M_PI / 180)));
  projection.y = (pos3d.x * cos(angle * M_PI / 180)) - (pos3d.z);
  return (projection);
}
