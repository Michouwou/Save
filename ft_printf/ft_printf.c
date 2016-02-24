/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 09:15:03 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 12:40:34 by mlevieux         ###   ########.fr       */
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
		ft_get_arg(trail, &print, &args);
		trail = trail->next;
	}
	ft_putstr(print);
	i = ft_strlen(print);
	ft_free_list(&forms);
	return (i);
}
