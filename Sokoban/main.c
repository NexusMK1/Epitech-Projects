#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "map.h"
#include "my.h"

t_map		*file_read(t_map *map, char *str)
{
  FILE		*rd;
  char		*buffer;
  char		*tmp;
  size_t	len;

  if ((rd = fopen(str, "r")) == 0)
    {
      map->ret_value = 84;
      my_puterr("Error: Unable to open the file.\n");
      return (map);
    }
  else
    while (getline(&buffer, &len, rd) != -1)
      {
	tmp = my_strdup(buffer);
	if (my_strlen(buffer)> map->width)
	  map->width = my_strlen(buffer) - 1;
	map->map[map->height] = tmp;
	map->height++;
      }
  return (map);
}

int		map_check(t_map *map)
{
  int		x;
  int		y;
  int		box;
  int		hole;
  int		p;

  x = y = box = hole = p = 0;
  if (map->height <= 1 || map->width <= 1)
    return (84);
  while (y < map->height)
    {
      while (map->map[y][x] != 0)
	{
	  box += map_cmp(map->map[y][x], 'X');
	  hole += map_cmp(map->map[y][x], 'O');
	  p += map_cmp(map->map[y][x], 'P');
	  x++;
	}
      x = 0;
      y++;
    }
  if (box != hole || p != 1)
    return (84);
  return (0);
}

t_map		*get_backup(t_map *map)
{
  char		**tmp;
  int		i;

  i = 0;
  tmp = malloc(sizeof(char) * 4096);
  while (i < map->height)
    {
      tmp[i] = malloc(sizeof(char) * my_strlen(map->map[i]));
      tmp[i] = my_strdup(map->map[i]);
      i++;
    }
  map->backup = tmp;
  return (map);
}

int		main(int argc, char **argv)
{
  t_map		*map;

  map = malloc(sizeof(t_map));
  map->map = malloc(sizeof(char) * 4096);
  if (argc != 2)
    {
      my_puterr("Error: No file specified. Use ./my_sokoban -h for help.\n");
      return (84);
    }
  if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == 0)
    {
      write_man();
      return (84);
    }
  map = file_read(map, argv[1]);
  if (map->ret_value == 84)
    return (84);
  if (map_check(map) == 84)
    {
      my_puterr("Error: Invalid map.\n");
      return (84);
    }
  map = get_backup(map);
  map->ret_value = sokoban(map);
  return (map->ret_value);
}
