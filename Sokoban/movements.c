#include "map.h"
#include "my.h"

void	move_up(t_map **map)
{
  int	x;
  int	y;

  x = get_playerx(map);
  y = get_playery(map);
  if ((*map)->map[y - 1][x] == 'X')
    {
      if ((*map)->map[y - 2][x] != 'X')
	{
	  if ((*map)->map[y - 2][x] == 'O')
	    (*map)->map[y - 2][x] = 'X';
	  else if ((*map)->map[y - 2][x] != '#'
		   && (*map)->map[y - 2][x] != 'X')
	    (*map)->map[y - 2][x] = 'X';
	  if ((*map)->map[y - 2][x] != '#')
	    (*map)->map[y - 1][x] = ' ';
	}
    }
  if ((*map)->map[y - 1][x] != '#' && (*map)->map[y - 1][x] != 'X')
    {
      (*map)->map[y - 1][x] = 'P';
      (*map)->map[y][x] = ' ';
    }
}

void    move_down(t_map **map)
{
  int   x;
  int   y;

  x = get_playerx(map);
  y = get_playery(map);
  if ((*map)->map[y + 1][x] == 'X')
    {
      if ((*map)->map[y + 2][x] != 'X')
	{
	  if ((*map)->map[y + 2][x] == 'O')
	    (*map)->map[y + 2][x] = 'X';
	  else if ((*map)->map[y + 2][x] != '#'
		   && (*map)->map[y + 2][x] != 'X')
	    (*map)->map[y + 2][x] = 'X';
	  if ((*map)->map[y + 2][x] != '#')
	    (*map)->map[y + 1][x] = ' ';
	}
    }
  if ((*map)->map[y + 1][x] != '#' && (*map)->map[y + 1][x] != 'X')
    {
      (*map)->map[y + 1][x] = 'P';
      (*map)->map[y][x] = ' ';
    }
}

void    move_left(t_map **map)
{
  int   x;
  int   y;

  x = get_playerx(map);
  y = get_playery(map);
  if ((*map)->map[y][x - 1] == 'X')
    {
      if ((*map)->map[y][x - 2] != 'X')
	{
	  if ((*map)->map[y][x - 2] == 'O')
	    (*map)->map[y][x - 2] = 'X';
	  else if ((*map)->map[y][x - 2] != '#'
		   && (*map)->map[y][x - 2] != 'X')
	    (*map)->map[y][x - 2] = 'X';
	  if ((*map)->map[y][x - 2] != '#')
	    (*map)->map[y][x - 1] = ' ';
	}
    }
  if ((*map)->map[y][x - 1] != '#' && (*map)->map[y][x - 1] != 'X')
    {
      (*map)->map[y][x - 1] = 'P';
      (*map)->map[y][x] = ' ';
    }
}

void    move_right(t_map **map)
{
  int   x;
  int   y;

  x = get_playerx(map);
  y = get_playery(map);
  if ((*map)->map[y][x + 1] == 'X')
    {
      if ((*map)->map[y][x + 2] != 'X')
	{
	  if ((*map)->map[y][x + 2] == 'O')
	    (*map)->map[y][x + 2] = 'X';
	  else if ((*map)->map[y][x + 2] != '#'
		   && (*map)->map[y][x + 2] != 'X')
	    (*map)->map[y][x + 2] = 'X';
	  if ((*map)->map[y][x + 2] != '#')
	    (*map)->map[y][x + 1] = ' ';
	}
    }
  if ((*map)->map[y][x + 1] != '#' && (*map)->map[y][x + 1] != 'X')
    {
      (*map)->map[y][x + 1] = 'P';
      (*map)->map[y][x] = ' ';
    }
}

void	put_objectives(t_map **map)
{
  int   x;
  int   y;

  x = y = 0;
  while (y < (*map)->height)
    {
      while ((*map)->map[y][x] != 0)
	{
	  if ((*map)->backup[y][x] == 'O')
	    if ((*map)->map[y][x] == ' ')
	      (*map)->map[y][x] = 'O';
	  x++;
	}
      x = 0;
      y++;
    }
}
