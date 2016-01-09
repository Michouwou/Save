#ifndef _FT_PRINTF
#define _FT_PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_putlong(char format, long num);
int	ft_putstring(char format, char *string);
int	ft_putdouble(char format, double num);
int	ft_putpointer(char format...);
void	ft_base(int num, int base);
void	ft_toupper(char *str);
void	ft_dispdouble(int acc, double num);
int	ft_printf(char *format, ...);

#endif
