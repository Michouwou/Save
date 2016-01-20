/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:05:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:20:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_pointer(unsigned address, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	result = ft_watoi(address, 16);
	result = ft_set_length(trail, result);
	result = ft_set_width(result, trail);
	print = ft_repstr(print, trail->start_index, trail->end_index, result);
}
