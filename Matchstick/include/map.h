#ifndef MAP_H_
#define MAP_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct		s_map
{
  char			**map;
  int			size;
  int			max;
  int			matches;
  int			mod;
}			t_map;

int			my_put_errnbr(int nb);
int			my_puterr(char *str, int x);
int			my_retstr(char *str, int x);
int			matchsticks(t_map *map);
int			player_process(t_map *map, char *buffer);
int			check_victory(t_map *map, int turn);
int			get_match(t_map *map, int line);
int			match_count(t_map *map, int line);
int			remove_matches(t_map *map, int line, int amount, int ia);
void			print_map(t_map *map);

#endif /* MAP_H_ */
