#include "my_framebuffer.h"
#include "my.h"
#include "map.h"

sfVector2f	get_position(t_map *map)
{
  sfVector2f	pos;
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y <= map->size.y)
    {
      while (x <= map->size.x)
	{
	  if (map->map[y][x] == 2)
	    {
	      pos.x = x;
	      pos.y = y;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
  return (pos);
}
