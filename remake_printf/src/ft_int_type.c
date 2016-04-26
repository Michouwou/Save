#include "libftprintf.h"

int		ft_int_type(T_LIST *args_data, va_list *args, char **result)
{
	int		m;

	m = (args_data) ? 1 : 0;
	if (args_data->format == 'D')
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (args_data->format == 'O' || args_data->format == 'U')
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long long), args_data,
			result));
	else if (!ft_strcmp(args_data->mod, "ll") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && !args_data->is_signed)
		return (ft_call_int((unsigned char)va_arg(*args, unsigned), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && args_data->is_signed)
		return (ft_call_int((char)va_arg(*args, int), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && !args_data->is_signed)
		return (ft_call_int((unsigned short)va_arg(*args, unsigned), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && args_data->is_signed)
		return (ft_call_int((short)va_arg(*args, int), args_data, result));
	else if (!ft_strcmp(args_data->mod, "j") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, uintmax_t), args_data, result));
	else if (!ft_strcmp(args_data->mod, "j") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, intmax_t), args_data, result));
	else if (!ft_strcmp(args_data->mod, "z") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, size_t), args_data, result));
	else if (!args_data->mod && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned), args_data, result));
	else
		return (ft_call_int(va_arg(*args, int), args_data, result));
}