#include "map.h"
#include "my.h"

int     victory_check(t_map **map)
{
  int   x;
  int   y;
  int   ret;

  x = y = ret = 0;
  while (y < (*map)->height)
    {
      while ((*map)->map[y][x] != 0)
	{
	  if ((*map)->backup[y][x] == 'O' && (*map)->map[y][x] != 'X')
	    ret = 1;
	  x++;
	}
      x = 0;
      y++;
    }
  if (player_stuck(map) == 1)
    ret = 84;
  return (ret);
}

int	check_box_sides(t_map **map, int x, int y)
{
  int	ret;

  ret = 0;
  if ((*map)->map[y + 1][x] == '#')
    ret++;
  if ((*map)->map[y - 1][x] == '#')
    ret++;
  if ((*map)->map[y][x + 1] == '#')
    ret++;
  if ((*map)->map[y][x - 1] == '#')
    ret++;
  if (ret == 2)
    {
      if ((*map)->map[y - 1][x] == '#' && (*map)->map[y + 1][x] == '#')
	ret--;
      if ((*map)->map[y][x - 1] == '#' && (*map)->map[y][x + 1] == '#')
	ret--;
    }
  return (ret);
}

int     defeat_check(t_map **map)
{
  int   x;
  int   y;
  int	box;
  int	stuck;

  x = y = box = stuck = 0;
  while (y < (*map)->height)
    {
      while ((*map)->map[y][x] != 0)
	{
	  if ((*map)->map[y][x] == 'X')
	    {
	      box++;
	      if (check_box_sides(map, x, y) > 1)
		stuck++;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
  if (box == stuck)
    return (1);
  else
    return (0);
}

int     player_stuck(t_map **map)
{
  int   x;
  int   y;

  x = get_playerx(map);
  y = get_playery(map);
  if ((*map)->map[y - 1][x] == '#')
    if ((*map)->map[y + 1][x] == '#')
      if ((*map)->map[y][x - 1] == '#')
	if ((*map)->map[y][x + 1] == '#')
	  return (1);
  return (0);
}

int     close_window(int ret)
{
  endwin();
  return (ret);
}
