/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:53:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:18:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_float(long double number, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	number = ft_float_apply_mod(trail, number);
	result = ft_conv_float(number, trail->accuracy);
	result = ft_set_width(result, trail);
	result = ft_apply_flag(result, trail);
	print = ft_repstr(print, trail->start_index, trail->end_index, result);
}
