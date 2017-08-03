#include "my.h"

int	my_put_oct(int nb);

int	my_putnprint(char *str)
{
  int	i;
  int	print;

  i = 0;
  print = 0;
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  print = print + my_put_oct(str[i]);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return (print + i);
}
