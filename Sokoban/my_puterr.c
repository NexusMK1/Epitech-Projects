#include <unistd.h>

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

int	my_puterr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar_e(str[i]);
      i++;
    }
  return (i);
}
