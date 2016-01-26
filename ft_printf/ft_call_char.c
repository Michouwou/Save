/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:50:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 17:35:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_char(wchar_t wc, T_LIST *trail, char **print)
{
	char	*result;

	wc = ft_char_apply_mod(trail, wc);
	result = (char*)ft_transfer_wchar(wc);
	result = ft_repstr(result, 0, 0, ft_strset(ft_strnew(trail->width - 1),
					trail->width - 1, ' '));
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
}
