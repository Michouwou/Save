/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:05:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 15:30:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_pointer(unsigned address, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	ft_check_pointer(address, trail);
	if (trail->mod)
		ft_error(1);
	result = ft_watoi(number, 16);
	result = ft_set_length(trail, result);
	result = ft_point_set_width(result, trail);
	result = ft_point_apply_flag(result, trail);
	ft_repstr(print, trail, result);
}
