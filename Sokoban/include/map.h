#ifndef	MAP_H_
#define	MAP_H_

#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_map
{
  char		**map;
  char		**backup;
  int		height;
  int		width;
  int		ret_value;
}		t_map;

char		*my_strmemcat(char *dest, char *src);
char		*my_strdup(char *str);
int		my_puterr(char *str);
t_map		*get_backup(t_map *map);
t_map		*load_backup(t_map *map);
int		sokoban(t_map *map);
int		get_playerx(t_map **map);
int		get_playery(t_map **map);
int		victory_check(t_map **map);
int		defeat_check(t_map **map);
int		player_stuck(t_map **map);
int		map_cmp(char src, char cmp);
int		close_window(int ret);
void		move_up(t_map **map);
void		move_down(t_map **map);
void		move_left(t_map **map);
void		move_right(t_map **map);
void		put_objectives(t_map **map);
void		write_man();

#endif /* MAP_H_ */
