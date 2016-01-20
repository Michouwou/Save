/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:50:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:16:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_char(wchar_t wc, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	result = ft_wstrnew((trail->width > 1) ? trail->width : 1);
	ft_wstrset(result, ft_wstrlen(result) - 2, ' ');
	wc = ft_char_apply_mod(trail, wc);
	result[ft_wstrlen(result)] = wc;
	print = ft_repstr(print, trail, result);
}
