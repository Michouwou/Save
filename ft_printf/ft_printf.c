/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 09:15:03 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 17:44:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char const *format, ...)
{
	va_list		args;
	T_LIST		*forms;
	T_LIST		*trail;
	char		*print;
	int			i;

	va_start(args, format);
	ft_check_format((char*)format);
	forms = ft_find_form((char*)format);
	trail = forms;
	print = (char*)format;
	while (trail != NULL)
	{
		if (T_ == 'd')
			ft_call_int(va_arg(args, intmax_t), trail, &print);
		if (T_ == 'p')
			ft_call_pointer(va_arg(args, unsigned), trail, &print);
		if (T_ == 'c')
			ft_call_char(va_arg(args, wchar_t), trail, &print);
		if (T_ == 'S' && trail->format == 's')
			ft_call_wstring(ft_conv_wchar(va_arg(args, char*)), trail, &print);
		else if (T_ == 'S')
			ft_call_wstring(va_arg(args, wchar_t*), trail, &print);
		if (T_ == 'f')
			ft_call_float(va_arg(args, double), trail, &print);
		trail = trail->next;
	}
	ft_putstr(print);
	i = ft_strlen(print);
	ft_free_list(&forms);
	return (i);
}
