#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

void		my_putchar(char c);
int		my_putstr(char *str);
int		my_put_nbr(int nb);
int		my_put_unbr(int nb);
int		my_put_binary(int nb);
int		my_put_oct(int nb);
int		my_put_hex(int nb);
int		my_put_hex_nc(int nb);
int		my_putnprint(char *str);

typedef struct	s_format
{
  int		i;
  int		ret;
}		t_format;

char		*format_flags(char *format, t_format *pos)
{
  char		*flags;
  int		j;

  j = 0;
  flags = malloc(sizeof(char) * my_strlen(format));
  if (flags == 0)
    return (0);
  while (j != 1 && format[pos->i] != '%'
	 && format[pos->i] != 0)
    {
      flags[j] = format[pos->i];
      pos->i++;
      j++;
    }
  return (flags);
}

char		*printf_format(char *format, t_format *pos)
{
  if (format[pos->i] != '%')
    {
      my_putchar(format[pos->i]);
      pos->ret++;
    }
  else
    {
      if (format[pos->i + 1] == 0)
	return (0);
      else
	{
	  pos->i++;
	  if (format[pos->i] == '%')
	    {
	      my_putchar('%');
	      pos->ret++;
	      pos->i++;
	      return (0);
	    }
	  return (format_flags(format, pos));
	}
    }
  pos->i++;
  return (0);
}

void		printf_fptr_set(int **fptr)
{
  fptr['s'] = &my_putstr;
  fptr['c'] = &my_putchar;
  fptr['d'] = &my_put_nbr;
  fptr['i'] = &my_put_nbr;
  fptr['u'] = &my_put_unbr;
  fptr['b'] = &my_put_binary;
  fptr['o'] = &my_put_oct;
  fptr['S'] = &my_putnprint;
  fptr['x'] = &my_put_hex;
  fptr['X'] = &my_put_hex_nc;
  fptr['p'] = &my_put_hex;
}

void		flags_conv(t_format *pos, char *flags, int arg)
{
  int		i;
  int		j;
  int		lock;
  char		*p_flags;
  int		(**fptr)(int);

  lock = i = j = 0;
  fptr = malloc(sizeof(char) * 128);
  p_flags = "scdiuboSxXp\0";
  printf_fptr_set(fptr);
  while (flags[i] != 0)
    {
      while (flags[i] != p_flags[j] && p_flags[j] != 0)
	j++;
      if (p_flags[j] != 0 && lock == 0)
	{
	  lock = 1;
	  pos->ret = pos->ret + fptr[flags[i]](arg);
	}
      else if (p_flags[j] == 0 && lock == 1)
	my_putchar(flags[i]);
      j = 0;
      i++;
    }
}

int		my_printf(char *format, ...)
{
  va_list	arg;
  char		*flags;
  t_format	*pos;

  pos = malloc(sizeof(t_format));
  pos->i = 0;
  pos->ret = 0;
  va_start(arg, format);
  if (format == 0)
    return (-1);
  if (my_strlen(format) == 0)
    return (0);
  while (format[pos->i] != 0)
    {
      flags = printf_format(format, pos);
      if (flags != 0)
	flags_conv(pos, flags, va_arg(arg, int));
    }
  va_end(arg);
  return (pos->ret);
}
