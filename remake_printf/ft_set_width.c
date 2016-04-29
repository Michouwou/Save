#include "libftprintf.h"

char    *ft_set_width(char *result, T_LIST *trail, int *state_value)
{
	int i;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != '+' && result[i] != '-' &&
			result[i] != 0 && (trail->type == 'd' || trail->type == 'f'))
		i++;
	if (trail->width > (int)ft_strlen(result))
	{
		if (!(trail->minus))
		{
			if (trail->z_pad && !(trail->accuracy > -1 && trail->type == 'd'))
				result = ft_repstr(result, (result[i] == '+' || result[i] == '-'
							) ? i = i + 1 : i, i,
						ft_strset(ft_strnew(trail->width - ft_strlen(result)),
							trail->width - ft_strlen(result), '0'));
			else
				result = ft_repstr(result, i, i,
						ft_strset(ft_strnew(trail->width - ft_strlen(result)),
							trail->width - ft_strlen(result), ' '));
		}
		else
			result = ft_repstr(result, ft_strlen(result), ft_strlen(result),
					ft_strset(ft_strnew(trail->width - ft_strlen(result)),
						trail->width - ft_strlen(result), ' '));
	}
	return (result);
}
