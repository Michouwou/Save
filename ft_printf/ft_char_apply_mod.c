/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_apply_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:29:40 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 14:33:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t		ft_char_apply_mod(T_LIST *trail, wchar_t wc)
{
	char *c;
	char t;

	c = trail->mod;
	t = trail->format;
	if (c == "l")
		return ((wint_t)wc);
	else if (!c && t == 'c')
		return ((char)wc);
}
