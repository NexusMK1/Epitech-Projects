#include "map.h"
#include "my.h"

void		print_map(t_map *map)
{
  int		width;
  int		x;
  int		y;

  x = y = 0;
  width = (map->size * 2) - 1;
  while (y != map->size + 2)
    {
      my_putchar('*');
      while (x != width  && (y == 0 || y == map->size + 1))
	{
	  my_putchar('*');
	  x++;
	}
      if (y != 0 && y != map->size + 1)
	my_putstr(map->map[y]);
      my_putstr("*\n");
      x = 0;
      y++;
    }
}

void		create_map(t_map *map)
{
  int		x;
  int		y;
  int		nb;
  int		match;

  nb = 1;
  x = y = match = 0;
  while (y <= map->size)
    {
      map->map[y] = malloc(sizeof(char) * (map->size * 2 - 1));
      while (x != (map->size * 2) - 1)
	{
	  if (match < nb - 2 && x >= (map->size - (nb / 2) - match))
	    {
	      match++;
	      map->map[y][x] = '|';
	    }
	  else
	    map->map[y][x] = ' ';
	  x++;
	}
      match = x = 0;
      nb += 2;
      y++;
    }
}

int		error_check(int argc, char **argv)
{
  int		nb;

  if (argc != 3)
    return (84);
  if (my_strlen(argv[1]) > 3)
    return (84);
  if (argv[1][0] < '0' || argv[1][0] > '9')
    return (84);
  if (my_strlen(argv[1]) > 1)
    if (argv[1][1] < '0' || argv[1][1] > '9')
      return (84);
  if (my_strlen(argv[1]) == 3)
    if (argv[1][2] < '0' || argv[1][2] > '9')
      return (84);
  nb = my_getnbr(argv[1]);
  if (nb <= 0 || nb > 100)
    return (84);
  return (0);
}

int		main(int argc, char **argv)
{
  t_map		*map;
  int		result;

  if (error_check(argc, argv) == 84)
    return (84);
  map = malloc(sizeof(t_map));
  map->max = my_getnbr(argv[2]);
  map->size = my_getnbr(argv[1]);
  map->map = malloc(sizeof(char) * (map->size * map->size + 1));
  create_map(map);
  result = matchsticks(map);
  if (result == -1)
    result = 0;
  free(map);
  return (result);
}
