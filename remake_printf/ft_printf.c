/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/22 16:40:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_int_type(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->format == 'D')
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (args_data->format == 'O' || args_data->format == 'U')
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned char), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, char), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned short), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, short), args_data, result));
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

int		ft_char_type(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->format == 'C' || (args_data->format == 'c' &&
				!ft_strcmp(args_data->mod, "l")))
		return (ft_call_char(va_arg(*args, wchar_t), args_data, result));
	else
		return (ft_call_char(va_arg(*args, char), args_data, result));
}

int		ft_double_type(T_LIST *args_data, va_list *args, char **result)
{
	if (!ft_strcmp(args_data->mod, "L"))
		return (ft_call_float(va_arg(*args, long double), args_data, result));
	else
		return (ft_call_float(va_arg(args, double), args_data, result));
}

int		ft_type_crossroad(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->type == INT_TYPE)
		return (ft_int_type(args_data, args, result));
	else if (args_data->type == CHAR_TYPE)
		return (ft_char_type(args_data, args, result));
	else if (args_data->type == POINTER_TYPE)
		return (ft_call_pointer(args_data, args, result));
	else if (args_data->type == STRING_TYPE)
		return (ft_call_string(args_data, args, result));
	else if (args_data->type == WSTRING_TYPE)
		return (ft_call_wstring(args_data, args, result));
	else if (args_data->type == DOUBLE_TYPE)
		return (ft_double_type(args_data, args, result));
	else if (args_data->type == ERRNO)
		return (ft_call_errno(args_data, args, result));
	else if (args_data->type == PERCENT)
		return (ft_call_percent(args_data, args, result));
	else
		return (ft_call_wildcard(args_data, args, result));
}

int		ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	int			buffer;
	T_LIST		*args_data;
	char		result;

	*buffer = 0;
	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = ft_check_fmt(fmt);
	args_data = ft_get_args(fmt, &buffer);
	while (args_data)
	{
		if (args_data->width == -1)
			args_data->width = va_arg(args, int);
		if (args_data->accuracy == -1)
			args_data->accuracy = va_arg(args, int);
		state_value = state_value & ft_type_crossroad(args_data, &args, &result);
		args_data = args_data->next;
	}
	ft_putstr(result);
	ft_free_data_args(data_args);	
	return (state_value ? *buffer : -1);
}
