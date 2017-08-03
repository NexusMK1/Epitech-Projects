#include "get_next_line.h"
#include "map.h"
#include "my.h"

int	player_process(t_map *map, char *buffer)
{
  int	matches;
  int	line;

  my_putstr("Line: ");
  if ((buffer = get_next_line(0)) == NULL)
    return (-1);
  line = my_getnbr(buffer);
  if (line <= 0 || line > map->size)
    return (my_retstr("Error: this line is out of range\n", 0));
  my_putstr("Matches: ");
  if ((buffer = get_next_line(0)) == NULL)
    return (-1);
  matches = my_getnbr(buffer);
  if (matches < 0)
    return (my_retstr("Error: invalid input (positive number expected)\n",
			 0));
  if (remove_matches(map, line, matches, 0) == 84)
    return (0);
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  return (1);
}
