#include "libftprintf.h"

char    *ft_strset(char *str, int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
