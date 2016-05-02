#include "libftprintf.h"

void	ft_get_accuracy(char *format, int *j, T_LIST *trail)
{
	int	i;
	
	(*j)++;
	i = *j;
	while (format[*j] && (ft_isdigit(format[*j]) || format[*j] == '*'))
	{
		if (format[*j] == '*')
		{
			trail->accuracy = -10;
			return;
		}
		(*j)++;
	}
	trail->accuracy = ft_atoi(ft_strsub(format, i, *j - i));
	if (i == *j)
		trail->accuracy = 0;
	(*j) -= 1;
}
