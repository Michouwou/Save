/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:00:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 14:20:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_int(T_LIST *t, char *print, va_list *args)
{
	int		sign;

	sign = (t->format == 'D' || t->mod == 'i' || t->mod == 'd') ? 1 : 0;
	if (!ft_strcmp(trail->mod, "ll") && sign)
		ft_call_int(va_arg(*args, long long), trail, print);
	else if (!ft_strcmp(trail->mod, "ll") && !sign)
		ft_call_int(va_arg(*args, unsigned long long), trail, print);
	else if ((!ft_strcmp(trail->mod, "l") && sign) || t->format == 'U' ||
			t->format == 'O')
		ft_call_int(va_arg(*args, long), trail, print);
	else if ((!ft_strcmp(trail->mod, "l") && !sign) || t->format == 'D')
		ft_call_int(va_arg(*args, unsigned long), trail, print);
	else if (trail->mod[0] == 0 && sign)
		ft_call_int(va_arg(*args, int), trail, print);
	else if (trail->mod[0] == 0 && !sign)
		ft_call_int(va_arg(*args, unsigned), trail, print);
	else if (!ft_strcmp(trail->mod, "h") && sign)
		ft_call_int(va_arg(*args, short), trail, print);
	else if (!ft_strcmp(trail->mod, "h") && !sign)
		ft_call_int(va_arg(*args, unsigned short), trail, print);
	else if (!ft_strcmp(trail->mod, "hh") && sign)
		ft_call_int(va_arg(*args, char), trail, print);
	else if (!ft_strcmp(trail->mod, "hh") && !sign)
		ft_call_int(va_arg(*args, unsigned char), trail, print);
}
