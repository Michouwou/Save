#include "libftprintf.h"

int		ft_call_wildcard(T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	state_value = 1;
	result = (trail->format) ? ft_strset(ft_strnew(1), 1, trail->format) : ft_strnew(0);
	if (!trail->format)
		trail->width--;
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result));
	return (state_value);
}
