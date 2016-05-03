#include "libftprintf.h"

char *ft_apply_flag(char *result, T_LIST *trail, int *state_value)
{
	char t;

	t = trail->format;
	if ((trail->type == 'd' || trail->type == 'f') && (trail->plus ||
				trail->space || result[0] == '-'))
	{
		if (trail->plus && ft_isdigit(result[0]) && (trail->is_signed ||
			trail->type == 'f'))
			result = ft_repstr(result, 0, 0, "+");
		else if (trail->space && ft_isdigit(result[0]) && trail->is_signed)
			result = ft_repstr(result, 0, 0, " ");
	}
	return (result);
}
