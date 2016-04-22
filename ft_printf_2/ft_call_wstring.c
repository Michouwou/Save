/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 14:49:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_wstring(wchar_t *wstring, T_LIST *trail, char **print)
{
	char *result;

	wstring = ft_wstring_apply_mod(trail, wstring);
	result = ft_transfer_wchars(wstring);
	result = ft_set_length(trail, result);
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
}
