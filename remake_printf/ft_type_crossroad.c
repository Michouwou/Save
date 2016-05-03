/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_crossroad.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:11:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 09:57:11 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_type_crossroad(T_LIST *args_data, va_list *args, char **res, int *buffer)
{
	if (args_data->type == INT_TYPE)
		return (ft_int_type(args_data, args, res));
	else if (args_data->type == CHAR_TYPE)
		return (ft_char_type(args_data, args, res, buffer));
	else if (args_data->type == POINTER_TYPE)
		return (ft_call_pointer(va_arg(*args, unsigned long), args_data, res));
	else if (args_data->type == STRING_TYPE && args_data->mod[0] == '-')
		return (ft_call_wstring(ft_conv_wchar(va_arg(*args, char*)), args_data,
			res));
	else if (args_data->type == WSTRING_TYPE ||
			(args_data->type == STRING_TYPE &&
				!ft_strcmp(args_data->mod, "l")))
		return (ft_call_wstring(va_arg(*args, wchar_t*), args_data, res));
	else if (args_data->type == DOUBLE_TYPE)
		return (ft_double_type(args_data, args, res));
	else if (args_data->type == ERRNO)
		return (ft_call_errno(args_data, res));
	else if (args_data->type == PERCENT)
		return (ft_call_percent(args_data, res));
	else if (args_data->incomplete)
		return (ft_call_wildcard(args_data, res));
	else
		return (0);
}
