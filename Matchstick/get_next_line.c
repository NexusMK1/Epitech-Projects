#include "get_next_line.h"
#include "my.h"

char		*get_line(char *remains, char *line,
			 int pos, int *start)
{
  int		tmp;
  char		*newline;

  tmp = 0;
  if (line != 0)
    tmp = my_strlen(line);
  newline = malloc(sizeof(char) * (tmp + pos + 1));
  if (line != 0)
    my_strncpy(newline, line, tmp);
  my_strncpy(newline + tmp, remains + *start, pos);
  newline[tmp + pos] = 0;
  *start = *start + (pos + 1);
  free(line);
  return (newline);
}

char		*get_next_line(const int fd)
{
  static char	remains[READ_SIZE + 1];
  static int	lstart = 0;
  static int	rd = 0;
  int		pos;
  char		*line;

  pos = 0;
  line = 0;
  while (1337)
    {
      if (lstart >= rd)
	{
	  lstart = pos = 0;
	  if ((rd = read(fd, remains, READ_SIZE)) == 0)
	    return (line);
	  if (rd == -1)
	    return (NULL);
	}
      if (remains[lstart + pos] == '\n')
	return (line = get_line(remains, line, pos, &lstart));
      if (lstart + pos == rd - 1)
	line = get_line(remains, line, pos + 1, &lstart);
      pos++;
    }
  return (line);
}
