/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:02:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 11:46:42 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <inttypes.h>
#include <unistd.h>
#include "libftprintf.h"
#include <stdlib.h>
#define LOC location->location

void	ft_printf(const char *format, ...)
{
	int		i;
	int		type;
	va_list	list_arg;
	t_list	*location;
	wchar_t	*res;


	va_start(list_arg, format);
	res = ft_wsstrdup(format);
	location = ft_find_form(res);
	while (location->next != NULL)
	{
		i = LOC;
		type = -1;
		while (ft_isdigit(format[i]) || ft_is_flag(format[i]) ||
				format[i] == '.' || !ft_what_type(format[i]))
		{
			if (ft_what_type(format[i]))
				type = ft_what_type(format[i]);
			i++;
		}
		if (type == 1)
			res = ft_call_int(va_arg(list_arg, intmax_t), &res, LOC, i);
		if (type == 2)
			res = ft_call_pointer(va_arg(list_arg, unsigned), &res, LOC, i);
		if (type == 3)
		{
			if (format[i] == 's' || format[i] == 'S')
				res = ft_call_string(va_arg(list_arg, *wchar_t), &res, LOC, i);
			if (format[i] == 'c' || format[i] == 'C')
				res = ft_call_char(va_arg(list_arg, wchar_t), &res, LOC, i);
		}
		else
			check_valid(res, location->location, i);
		location = location->next;
	}
	write(1, res, ft_wstrle(res));
	free(res);
}
