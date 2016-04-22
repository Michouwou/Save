/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 09:15:03 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/22 10:49:05 by mlevieux         ###   ########.fr       */
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
	if (!ft_check_format((char*)format))
		return (0);
	forms = ft_find_form((char*)format);
	trail = forms;
	print = (char*)format;
	while (trail != NULL)
	{
		if (trail->type == '%')
			print = ft_repstr(print, trail->start_index, trail->end_index + 1, "%");
		else
			ft_get_arg(trail, &print, &args);
		trail = trail->next;
	}
	ft_putstr(print);
	i = ft_strlen(print);
	ft_free_list(&forms);
	return (i);
}
