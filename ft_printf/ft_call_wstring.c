/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 15:52:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_wstring(wchar_t *wstring, T_LIST *trail, wchar_t *print)
{
	if (ft_check_wchar(result))
		ft_repstr(print, trail, wstring);
	if (trail->mod)
		ft_error(1);
	result = ft_set_length(trail, wstring);
	result = ft_wstring_set_width(wstring, trail);
	result = ft_wstring_apply_flag(wstring, trail);
	ft_repstr(print, trail, wstring);
}
