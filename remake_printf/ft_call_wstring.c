/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:51:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/05 11:43:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_call_wstring(wchar_t *wstring, T_LIST *trail, char **print, int code)
{
	char			*result;
	int				state_value;
	unsigned char 	*to_free;
	wchar_t			*tmp;

	state_value = 1;
	to_free = NULL;
	tmp = code == 0 ? wstring : NULL;
	if (!wstring)
		result = ft_strdup("(null)");
	else
		result = ft_transfer_wchars(wstring, trail, &to_free);
	result = ft_set_length(trail, result);
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	free(result);
	free(tmp);
	if (to_free)
		free(to_free);
	return (state_value);
}
