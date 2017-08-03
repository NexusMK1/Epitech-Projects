#include "my.h"

int	my_strlen(char *str)
{
  int	lenght;

  if (str == NULL)
    return (0);
  lenght = 0;
  while (str[lenght] != '\0')
    lenght = lenght + 1;
  return (lenght);
}
