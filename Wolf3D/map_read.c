#include <stdio.h>
#include "my_framebuffer.h"
#include "my.h"
#include "map.h"

t_map	*map_read(t_map *map, char *file)
{
  int	fd;

  map->error = 0;
  map->buffer = malloc(sizeof(char) * 4096);
  if ((fd = open(file, O_RDONLY)) == -1)
    map->error = 84;
  if (map->error != 84)
    if (read(fd, map->buffer, 4096) == -1)
      map->error = 84;
  close(fd);
  if (map->error != 84)
    map = get_map(map);
  return (map);
}

t_map	*get_map(t_map *map)
{
  int	i;
  int	x;
  int	y;

  i = x = y = 0;
  map->map = malloc(sizeof(int) * 4096);
  map->map[y] = malloc(sizeof(int) * 4096);
  while (map->buffer[i] != 0)
    {
      if (map->buffer[i] >= '0' && map->buffer[i] <= '9')
	{
	  map->map[y][x] = (map->buffer[i] - '0');
	  x++;
	}
      if (map->buffer[i] == '\n')
	{
	  map->size.x = x;
	  x = 0;
	  y++;
	  map->map[y] = malloc(sizeof(int) * 4096);
	}
      i++;
    }
  map->size.y = y;
  return (map);
}
