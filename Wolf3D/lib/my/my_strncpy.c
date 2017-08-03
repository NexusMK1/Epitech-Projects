#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (count < n)
    {
      dest[count] = src[count];
      count = count + 1;
    }
  dest[count] = '\0';
  return (dest);
}

char	*my_strxncpy(char *dest, char *src, int n, int x)
{
  int	count;
  int	start;

  count = x;
  start = 0;
  while (count < x + n)
    {
      dest[start] = src[count];
      count += 1;
      start += 1;
    }
  dest[start] = '\0';
  return (dest);
}
