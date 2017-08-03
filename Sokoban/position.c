#include "map.h"
#include "my.h"

int	get_playery(t_map **map)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < (*map)->height)
    {
      while (x < my_strlen((*map)->map[y]))
	{
	  if ((*map)->map[y][x] == 'P')
	    return (y);
	  x++;
	}
      x = 0;
      y++;
    }
  return (y);
}

int	get_playerx(t_map **map)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (y < (*map)->height)
    {
      while (x < my_strlen((*map)->map[y]))
	{
	  if ((*map)->map[y][x] == 'P')
	    return (x);
	  x++;
	}
      x = 0;
      y++;
    }
  return (x);
}

int	map_cmp(char src, char cmp)
{
  if (src == cmp)
    return (1);
  else
    return (0);
}
