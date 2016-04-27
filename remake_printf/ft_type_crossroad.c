#include "libftprintf.h"

int		ft_type_crossroad(T_LIST *args_data, va_list *args, char **result, int *buffer)
{
	if (args_data->type == INT_TYPE)
		return (ft_int_type(args_data, args, result));
	else if (args_data->type == CHAR_TYPE)
		return (ft_char_type(args_data, args, result, buffer));
	else if (args_data->type == POINTER_TYPE)
		return (ft_call_pointer(va_arg(*args, unsigned), args_data, result));
	else if (args_data->type == STRING_TYPE)
		return (ft_call_wstring(ft_conv_wchar(va_arg(*args, char*)), args_data,
			result));
	else if (args_data->type == WSTRING_TYPE)
	{
		return (ft_call_wstring(va_arg(*args, wchar_t*), args_data, result));
	}
	else if (args_data->type == DOUBLE_TYPE)
		return (ft_double_type(args_data, args, result));
	else if (args_data->type == ERRNO)
		return (ft_call_errno(args_data, result));
	else if (args_data->type == PERCENT)
		return (ft_call_percent(args_data, result));
	else
		return (ft_call_wildcard(args_data, result));
}