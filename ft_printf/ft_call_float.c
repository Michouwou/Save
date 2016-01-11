/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:53:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 16:19:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_float(double number, T_LIST *trail, wchar_t *result)
{
	wchar_t	*result;

	ft_check_float(number, trail);
	number = ft_float_apply_mod(trail, number);
	result = ft_conv_float()
}
