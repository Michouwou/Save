/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:01:32 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 11:21:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define U unsigned

int		ft_int_type(T_LIST *args_data, va_list *args, char **res)
{
	if (args_data->format == 'D')
		return (ft_call_int(va_arg(*args, long), args_data, res));
	else if (args_data->format == 'O' || args_data->format == 'U')
		return (ft_call_uint(va_arg(*args, U long), args_data, res));
	else if (!ft_strcmp(args_data->mod, "ll") && !args_data->is_signed)
		return (ft_call_uint(va_arg(*args, U long long), args_data,
			res));
	else if (!ft_strcmp(args_data->mod, "ll") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long long), args_data, res));
	else if (!ft_strcmp(args_data->mod, "l") && !args_data->is_signed)
		return (ft_call_uint(va_arg(*args, U long), args_data, res));
	else if (!ft_strcmp(args_data->mod, "l") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long), args_data, res));
	else if (!ft_strcmp(args_data->mod, "hh") && !args_data->is_signed)
		return (ft_call_uint((U char)va_arg(*args, U), args_data, res));
	else if (!ft_strcmp(args_data->mod, "hh") && args_data->is_signed)
		return (ft_call_int((char)va_arg(*args, int), args_data, res));
	else if (!ft_strcmp(args_data->mod, "h") && !args_data->is_signed)
		return (ft_call_uint((U short)va_arg(*args, U), args_data, res));
	else if (!ft_strcmp(args_data->mod, "h") && args_data->is_signed)
		return (ft_call_int((short)va_arg(*args, int), args_data, res));
	else if (!ft_strcmp(args_data->mod, "j") && !args_data->is_signed)
		return (ft_call_uint(va_arg(*args, uintmax_t), args_data, res));
	else if (!ft_strcmp(args_data->mod, "j") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, intmax_t), args_data, res));
	else if (!ft_strcmp(args_data->mod, "z") && !args_data->is_signed)
		return (ft_call_uint(va_arg(*args, size_t), args_data, res));
	else if (!ft_strcmp(args_data->mod, "z") && args_data->is_signed)
		return (ft_call_int((size_t)va_arg(*args, long long), args_data, res));
	else if (!ft_strcmp(args_data->mod, "-") && !args_data->is_signed)
		return (ft_call_uint(va_arg(*args, U), args_data, res));
	else
		return (ft_call_int(va_arg(*args, int), args_data, res));
}
