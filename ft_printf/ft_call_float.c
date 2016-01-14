/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:53:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 16:36:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_float(long double number, T_LIST *trail, wchar_t *print)
{
	wchar_t	*result;

	ft_check_float(&number, trail);
	number = ft_float_apply_mod(trail, number);
	result = ft_conv_float(number, trail);
	result = ft_float_set_width(result, trail);
	result = ft_float_apply_flag(result, trail);
	ft_repstr(print, trail, result);
}
