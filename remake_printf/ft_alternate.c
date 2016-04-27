#include "libftprintf.h"

char    *ft_alternate(char *result, T_LIST *trail)
{
	int i;

	i = 0;
	if (trail->format == 'o' || trail->format == 'O' || trail->format == 'x' ||
			trail->format == 'X' || trail->format == 'b')
	{
		while (!ft_isalnum(result[i]))
			i++;
		if (trail->format == 'o' || trail->format == 'O')
			result = ft_repstr(result, i, i, "0");
		else if (trail->format == 'x')
			result = ft_repstr(result, i, i, "0x");
		else if (trail->format == 'X')
			result = ft_repstr(result, i, i, "0X");
		else
			result = ft_repstr(result, i, i, "b");
	}
	else if (trail->type == 'f')
	{
		while (!ft_isdigit(result[i]))
			i++;
		while (ft_isdigit(result[i]))
			i++;
		if (result[i] != '.')
			result = ft_repstr(result, i, i, ".");
	}
	return (result);
}