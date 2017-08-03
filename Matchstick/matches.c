#include "map.h"
#include "my.h"

int	check_victory(t_map *map, int turn)
{
  int	x;
  int	y;

  x = y = 0;
  while (y <= map->size)
    {
      while (map->map[y][x] != 0)
	{
	  if (map->map[y][x] == '|')
	    return (0);
	  x++;
	}
      x = 0;
      y++;
    }
  return (turn + 1);
}

int	get_match(t_map *map, int line)
{
  int	pos;
  int	i;

  pos = i = 0;
  while (map->map[line][i] != 0)
    {
      if (map->map[line][i] == '|')
	pos = i;
      i++;
    }
  return (pos);
}

int	match_count(t_map *map, int line)
{
  int	count;
  int	i;

  count = i = 0;
  while (map->map[line][i] != 0)
    {
      if (map->map[line][i] == '|')
	count++;
      i++;
    }
  return (count);
}

int	remove_matches(t_map *map, int line, int amount, int ia)
{
  int	pos;
  int	i;

  if (amount == 0)
    return (my_retstr("Error: you have to remove at least one match\n", 84));
  if (amount > map->max && ia == 1)
    return (84);
  if (amount > map->max && ia == 0)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(map->max);
      return (my_retstr(" matches per turn\n", 84));
    }
  if (match_count(map, line) < amount && ia == 1)
    return (84);
  if (match_count(map, line) < amount && ia == 0)
    return (my_retstr("Error: not enough matches on this line\n", 84));
  pos = get_match(map, line);
  i = (pos - amount) + 1;
  while (i <= pos)
    {
      map->map[line][i] = ' ';
      i++;
    }
  return (0);
}
