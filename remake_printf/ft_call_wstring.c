/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:51:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 16:43:11 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_call_wstring(wchar_t *wstring, T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	state_value = 1;
	result = (wstring) ? ft_transfer_wchars(wstring, trail) :
		ft_strdup("(null)");
	result = ft_set_length(trail, result);
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}
