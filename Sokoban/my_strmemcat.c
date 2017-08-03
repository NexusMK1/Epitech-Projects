#include <stdlib.h>
#include <string.h>
#include "my.h"

char    *my_strmemcat(char *dest, char *src)
{
  int   count;
  int   char_count;
  char	*tmp;

  count = 0;
  char_count = 0;
  tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
  while (dest[count] != '\0')
    {
      tmp[count] = dest[count];
      count = count + 1;
    }
  while (char_count < my_strlen(src))
    {
      tmp[count] = src[char_count];
      count = count + 1;
      char_count = char_count + 1;
    }
  tmp[count] = '\0';
  return (tmp);
}

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc(sizeof(char) * my_strlen(str) + 1);
  while (i <= my_strlen(str))
    {
      dup[i] = str[i];
      i++;
    }
  return (dup);
}
