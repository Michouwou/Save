/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:23:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 15:40:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_string(char *string, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	if (ft_check_string(string, trail) == 0)
	{
		ft_repstr(print, trail, "");
		return;
	}
	result = ft_conv_wchar(string);
	result = ft_set_length(trail, result);
	result = ft_string_set_width(result, trail);
	result = ft_string_apply_flag(result, trail);
	ft_repstr(print, trail, result);
}
