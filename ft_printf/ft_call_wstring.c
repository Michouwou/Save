/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 17:07:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_wstring(wchar_t *wstring, T_LIST *trail, wchar_t **print)
{
	wchar_t *result;

	result = wstring;
	result = ft_wstring_apply_mod(trail, result);
	result = ft_set_length(trail, result);
	printf("\tCall_wstring length OK\n");
	NOW
	result = ft_set_width(result, trail);
	printf("\tCall_wstring width OK\n");
	NOW
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
}
