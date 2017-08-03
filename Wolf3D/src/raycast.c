#include "../include/my_framebuffer.h"
#include "../include/map.h"
#include "../include/my.h"

float		raycast(sfVector2f pos, float direction,
		int **map, sfVector2i mapSize)
{
  sfVector2f	ray_pos;
  float		ray;

  ray_pos.x = pos.x;
  ray_pos.y = pos.y;
  while (map[(int)ray_pos.y][(int)ray_pos.x] != 1)
    {
      if ((int)ray_pos.x > mapSize.x || (int)ray_pos.y > mapSize.y)
	return (84);
      ray_pos = move_forward(ray_pos, direction, 0.005);
    }
  ray = sqrtf(powf(ray_pos.x - pos.x, 2) + powf(ray_pos.y - pos.y, 2));
  return (ray);
}
