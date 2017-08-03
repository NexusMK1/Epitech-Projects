#include "my.h"

char	*my_strdup(char *str)
{
  char	*dup;
  int	x;

  x = -1;
  if ((dup = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[++x] != 0)
    dup[x] = str[x];
  dup[x] = '\0';
  return (dup);
}
