#include "libftprintf.h"

int    ft_call_float(long double number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	if (trail->format == 'f' || trail->format == 'F')
		result = ft_conv_float(number, (trail->accuracy != -1) ?
				trail->accuracy : 6);
	if (trail->format == 'e' || trail->format == 'E')
		result = ft_conv_exp(number, trail);
	if (trail->format == 'E')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}
