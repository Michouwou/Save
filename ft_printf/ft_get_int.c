/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:00:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 15:10:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define I_ intmax_t
#define U_ uintmax_t
#define US_ unsigned

void	ft_get_int(T_LIST *t, char **print, va_list *args)
{
	int		sign;

	sign = (M_ == 'D' || M_ == 'i' || M_ == 'd') ? 1 : 0;
	if (!ft_strcmp(t->mod, "ll") && sign)
		ft_call_int(va_arg(*args, long long), t, print);
	else if (!ft_strcmp(t->mod, "ll") && !sign)
		ft_call_int(va_arg(*args, unsigned long long), t, print);
	else if ((!ft_strcmp(t->mod, "l") && sign) || M_ == 'U' || M_ == 'O')
		ft_call_int(va_arg(*args, long), t, print);
	else if ((!ft_strcmp(t->mod, "l") && !sign) || M_ == 'D')
		ft_call_int(va_arg(*args, unsigned long), t, print);
	else if (t->mod[0] == 0 && sign)
		ft_call_int(va_arg(*args, int), t, print);
	else if (t->mod[0] == 0 && !sign)
		ft_call_int(va_arg(*args, unsigned), t, print);
	else if (!ft_strcmp(t->mod, "h") && sign)
		ft_call_int((short)va_arg(*args, int), t, print);
	else if (!ft_strcmp(t->mod, "h") && !sign)
		ft_call_int((unsigned short)va_arg(*args, unsigned), t, print);
	else if (!ft_strcmp(t->mod, "hh") && sign)
		ft_call_int((char)va_arg(*args, int), t, print);
	else if (!ft_strcmp(t->mod, "hh") && !sign)
		ft_call_int((unsigned char)va_arg(*args, unsigned), t, print);
	else if (!ft_strcmp(t->mod, "j") && sign)
		ft_call_int(va_arg(*args, intmax_t), t, print);
	else if (!ft_strcmp(t->mod, "j") && !sign)
		ft_call_int(va_arg(*args, uintmax_t), t, print);
	else if (!ft_strcmp(t->mod, "z"))
		ft_call_int(va_arg(*args, size_t), t, print);
}
