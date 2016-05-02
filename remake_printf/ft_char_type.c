#include "libftprintf.h"

int		ft_char_type(T_LIST *args_data, va_list *args, char **res, int *buf)
{
	if (args_data->format == 'C' || (args_data->format == 'c' &&
				!ft_strcmp(args_data->mod, "l")))
		return (ft_call_char((wchar_t)va_arg(*args, wchar_t), args_data, res, buf));
	else
		return (ft_call_char((char)va_arg(*args, wchar_t), args_data, res, buf));
}