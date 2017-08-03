#include "my_framebuffer.h"
#include "my.h"
#include "map.h"

int			window_create(sfVideoMode mode, sfTexture *texture,
				      t_my_framebuffer *buffer, t_map *map)
{
  sfRenderWindow	*window;
  sfSprite              *sprite;
  sfEvent		event;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, 0);
  window = sfRenderWindow_create(mode, "SFML window",
				 sfResize | sfClose, NULL);
  if (window == NULL)
    return (84);
  while (sfRenderWindow_isOpen(window))
    while (sfRenderWindow_pollEvent(window, &event))
      {
	buffer->pixels = malloc(sizeof(sfUint8) * mode.width * mode.height * 4);
	wolf(buffer, map);
	sfTexture_updateFromPixels(texture, buffer->pixels, buffer->width,
				   buffer->height, 0, 0);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_display(window);
	if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
	  sfRenderWindow_close(window);
      }
  sfRenderWindow_destroy(window);
  return (0);
}

int			error(int argc)
{
  if (argc != 2)
    {
      my_puterr("Error: Invalid argument count\n\nUSAGE\n\t./wolf3d map\n");
      return (84);
    }
  return (0);
}

int			main(int argc, char **argv)
{
  t_my_framebuffer	*buffer;
  sfVideoMode		mode = {1000, 1000, 32};
  sfTexture             *texture;
  t_map			*map;

  if (error(argc) == 84)
    return (84);
  buffer = my_framebuffer_create(mode.width, mode.height);
  texture = sfTexture_create(buffer->width, buffer->height);
  map = malloc(sizeof(t_map) * 4096);
  map = map_read(map, argv[1]);
  if (map->error == 84)
    {
      my_puterr("Error: Invalid map\n");
      return (84);
    }
  map->pos = get_position(map);
  map->pos.x += 0.5;
  map->pos.y += 0.5;
  map->view = 270;
  if (window_create(mode, texture, buffer, map) == 84)
    return (84);
  return (0);
}
