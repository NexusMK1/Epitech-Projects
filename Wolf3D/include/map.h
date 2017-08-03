#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>

typedef struct		s_map
{
  int			**map;
  char			*buffer;
  int			error;
  float			view;
  sfVector2i		size;
  sfVector2f		pos;
}			t_map;

void                    wolf(t_my_framebuffer *framebuffer, t_map *map);
t_map			*map_read(t_map *map, char *file);
t_map			*get_map(t_map *map);
sfVector2f		get_position(t_map *map);
#endif
