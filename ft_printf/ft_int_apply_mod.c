/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_apply_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:38:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 14:36:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	ft_int_apply_mod(T_LIST *trail, intmax_t number)
{
	char	*c;
	char	t;
	int		sign;

	c = trail->mod;
	t = trail->format;
	sign = (t == 'd' || t == 'D' || t == 'i') ? 1 : 0;
	if (c == "z")
		return ((size_t)number);
	else if (c == "h")
		return (sign ? (short)number : (unsigned short)number);
	else if (c == "hh")
		return (sign ? (char)number : (unsigned char)number);
	else if (c == "l")
		return (sign ? (long)number : (unsigned long)number);
	else if (c == "ll")
		return (sign ? (long long)number : (unsigned long long)number);
	else
		return (sign ? (int)number : (unsigned int)number);
}
