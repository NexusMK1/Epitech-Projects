#include "my.h"

int	my_putstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
  return (count);
}
