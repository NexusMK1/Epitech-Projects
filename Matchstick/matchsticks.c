#include "map.h"
#include "my.h"

int	player_turn(t_map *map)
{
  char	*buffer;
  int	i;

  i = 0;
  buffer = malloc(sizeof(char) * 1024);
  my_putstr("Your turn:\n");
  while (i == 0)
    i = player_process(map, buffer);
  my_putchar('\n');
  free(buffer);
  return (i);
}

int	ai_process(t_map *map, int i, int count)
{
  while (i < map->size)
    {
      count += match_count(map, i);
      i++;
    }
  i = count - 1;
  while (i % map->mod != 0)
    i--;
  i = count - i;
  return (i);
}

int	ai_turn(t_map *map)
{
  int	i;
  int	count;
  int	line;

  my_putstr("AI's turn...\n");
  i = count = 0;
  line = 1;
  i = ai_process(map, i, count);
  while (remove_matches(map, line, i, 1) == 84)
    {
      line++;
      if (line > map->size)
	{
	  line = 1;
	  i--;
	}
    }
  my_putstr("AI removed ");
  my_put_nbr(i);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
  return (0);
}

void	get_mod(t_map *map)
{
  int	i;

  i = 0;
  map->mod = 2;
  while (i < map->size)
    {
      map->matches += match_count(map, i);
      i++;
    }
  if (map->size != 2)
    while (map->matches % map->mod != 0)
      map->mod++;
}

int	matchsticks(t_map *map)
{
  int	result;
  int	turn;

  get_mod(map);
  result = turn = 0;
  while (result == 0)
    {
      print_map(map);
      my_putchar('\n');
      if (turn == 1)
	turn = ai_turn(map);
      else
	while (turn == 0)
	  turn = player_turn(map);
      result = check_victory(map, turn);
      if (turn == -1)
	return (0);
    }
  print_map(map);
  if (result == 1)
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  if (result == 2)
    my_putstr("You lost, too bad...\n");
  return (result);
}
