#include "map.h"

void	write_man()
{
  my_puterr("USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\t");
  my_puterr("file representing the warehouse map, containing \'#\' ");
  my_puterr("for walls,\n\t\t\'P\' for the player, \'X\'");
  my_puterr("for boxes and \'O\' for storage locations.\n");
}
