#include <stdio.h>
#include "my_framebuffer.h"
#include "my.h"
#include "map.h"

void		draw_bg(t_my_framebuffer *framebuffer)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < framebuffer->height)
    {
      while (x <= framebuffer->width)
	{
	  if (y <= (framebuffer->height / 2))
	    my_put_pixel(framebuffer, x, y,
			 sfColor_fromRGBA(130, 157, 218, 255 - (y / 5)));
	  else
	    my_put_pixel(framebuffer, x, y,
			 sfColor_fromRGBA(100, 165, 100, y / 5));
	  x++;
	}
      x = 0;
      y++;
    }
}

t_map		*p_movement(t_map *map)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    {
      if (map->map[(int)(map->pos.y + (0.2 * cos(map->view * M_PI / 180)))]
	  [(int)(map->pos.x + (0.2 * cos(map->view * M_PI / 180)))] != 1)
	if (map->map[(int)(map->pos.y + (0.2 * cos(map->view * M_PI / 180)))]
	    [(int)(map->pos.x)] != 1 && map->map[(int)(map->pos.y)]
	    [(int)(map->pos.x + (0.2 * sin(map->view * M_PI / 180)))] != 1)
	  {
	    map->pos.x += (0.05 * cos(map->view * M_PI / 180));
	    map->pos.y += (0.05 * sin(map->view * M_PI / 180));
	  }
    }
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    {
      if (map->map[(int)(map->pos.y - (0.2 * cos(map->view * M_PI / 180)))]
	  [(int)(map->pos.x - (0.2 * cos(map->view * M_PI / 180)))] != 1)
	if (map->map[(int)(map->pos.y - (0.2 * cos(map->view * M_PI / 180)))]
	    [(int)(map->pos.x)] != 1 && map->map[(int)(map->pos.y)]
	    [(int)(map->pos.x - (0.2 * sin(map->view * M_PI / 180)))] != 1)
	  {
	    map->pos.x -= (0.05 * cos(map->view * M_PI / 180));
	    map->pos.y -= (0.05 * sin(map->view * M_PI / 180));
	  }
    }
  return (map);
}

t_map		*movement(t_map *map)
{
  map = p_movement(map);
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      if (map->view == 0)
	map->view = 360;
      map->view -= 5;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      if (map->view == 360)
	map->view = 0;
      map->view += 5;
    }
  return (map);
}

void		wolf(t_my_framebuffer *framebuffer, t_map *map)
{
  sfVector2i	wall;
  sfVector2i	wall_e;
  float		angle;
  float		ray;
  int		i;

  map = movement(map);
  angle = map->view - 30;
  draw_bg(framebuffer);
  i = 0;
  while (i < framebuffer->width)
    {
      ray = raycast(map->pos, angle, map->map, map->size);
      wall.x = i;
      wall_e.x = wall.x;
      wall.y = (framebuffer->height / 2) -
	((300 / ray) / cos(0 - (map->view - angle) * (M_PI / 180)));
      wall_e.y = framebuffer->height - wall.y;
      my_draw_line(framebuffer, wall, wall_e,
		   sfColor_fromRGB(50 * ray / 3, 50 * ray / 3, 50 * ray / 3));
      angle += 0.06;
      i += 1;
    }
}
