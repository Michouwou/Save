/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:50:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/19 18:55:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_char(wchar_t wc, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	ft_check_char(&wc, trail);
	result = ft_wstrnew((trail->width > 1) ? trail->width : 1);
	wc = ft_char_apply_mod(trail, &wc);
	result[ft_wstrlen(result)] = wc;
	ft_repstr(print, trail, result);
}
