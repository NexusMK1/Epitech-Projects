#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strfcat(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strxncpy(char *dest, char *src, int n, int x);
int	my_printf(char *format, ...);

#endif	/* MY_H_ */
