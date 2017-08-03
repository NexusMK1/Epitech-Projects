#include "my.h"

char	*my_strcat(char *dest, char*src)
{
  char	*cat;
  int	x;
  int	y;

  x = y = 0;
  if ((cat = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1)))
      == NULL)
    return (NULL);
  while (dest[x] != '\0')
    {
      cat[x] = dest[x];
      x += 1;
    }
  while (src[y])
    {
      cat[x] = src[y];
      x += 1;
      y += 1;
    }
  cat[x] = '\0';
  return (cat);
}

char	*my_strfcat(char *dest, char*src)
{
  char	*cat;
  int	x;
  int	y;

  x = y = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  if ((cat = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1)))
      == NULL)
    return (NULL);
  while (dest[x] != '\0')
    {
      cat[x] = dest[x];
      x += 1;
    }
  while (src[y])
    {
      cat[x] = src[y];
      x += 1;
      y += 1;
    }
  cat[x] = '\0';
  free(dest);
  return (cat);
}
