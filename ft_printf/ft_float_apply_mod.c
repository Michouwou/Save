/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_apply_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:24:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 16:29:03 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double	ft_float_apply_mod(T_LIST *trail, long double number)
{
	char	*c;
	char	t;

	c = trail->mod;
	t = trail->format;
	if (c == "L")
		return ((long double)number);
	else
		return ((double)number);
}
