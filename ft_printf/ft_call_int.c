/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:02:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 15:29:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_int(intmax_t number, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	ft_check_int(number, trail);
	number = ft_int_apply_mod(trail, number);
	result = ft_watoi(number, trail->format);
	result = ft_set_length(trail, result); // Number of digits to print INSIDE the field
	result = ft_int_set_width(result, trail);
	result = ft_int_apply_flag(result, trail);
	ft_repstr(print, trail, result);
}
