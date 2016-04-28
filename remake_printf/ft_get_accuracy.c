#include "libftprintf.h"

void	ft_get_accuracy(char *location, int *counter, T_LIST *trail)
{
	int	i;
	
	(*counter)++;
	i = *counter;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->accuracy = ft_atoi(ft_strsub(location, i, *counter - i));
	if (i == *counter)
		trail->accuracy = 0;
	(*counter) -= 1;
}
