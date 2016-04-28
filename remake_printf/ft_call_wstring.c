#include "libftprintf.h"

int    ft_call_wstring(wchar_t *wstring, T_LIST *trail, char **print)
{
	char 	*result;
	int		state_value;

	state_value = 1;
	result = (wstring) ? ft_transfer_wchars(wstring, trail) : ft_strdup("(null)");
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}
