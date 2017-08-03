#include "my.h"
#include "map.h"

void	init()
{
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
}

void	print_map(t_map *map, int x, int y)
{
  int	max_x;
  int	max_y;
  int	i;

  i = 0;
  getmaxyx(stdscr, max_y, max_x);
  if (max_x > map->height && max_y > map->width)
    while (i < map->height)
      {
	mvprintw(y + i, x, map->map[i]);
	i++;
      }
  else
    mvprintw(max_y / 2, 0, "Expand the terminal.");
}

t_map	*load_backup(t_map *map)
{
  char          **tmp;
  int           i;

  i = 0;
  tmp = malloc(sizeof(char) * 4096);
  while (i < map->height)
    {
      tmp[i] = malloc(sizeof(char) * my_strlen(map->backup[i]));
      tmp[i] = my_strdup(map->backup[i]);
      i++;
    }
  map->map = tmp;
  return (map);
}

int	check_movement(t_map **map, int ch)
{
  if (ch == KEY_UP)
    move_up(map);
  if (ch == KEY_DOWN)
    move_down(map);
  if (ch == KEY_LEFT)
    move_left(map);
  if (ch == KEY_RIGHT)
    move_right(map);
  put_objectives(map);
  (*map)->ret_value = victory_check(map);
  return ((*map)->ret_value);
}

int	sokoban(t_map *map)
{
  int   ch;
  int   x;
  int   y;

  init();
  while (ch != 27)
    {
      getmaxyx(stdscr, y, x);
      x = (x / 2) - (map->width / 2);
      y = (y / 2) - (map->height / 2);
      erase();
      if (ch == ' ')
	{
	  map = load_backup(map);
	  map = get_backup(map);
	}
      if (check_movement(&map, ch) != 1)
	return (close_window(map->ret_value));
      if (defeat_check(&map) == 1)
	return (close_window(1));
      print_map(map, x, y);
      refresh();
      ch = getch();
    }
  return (close_window(map->ret_value));
}
