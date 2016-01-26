/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:02:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 14:23:12 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char	*result;

	number = ft_int_apply_mod(trail, number);
	if (trail->format != 'd' && trail->format != 'D' && trail->format != 'i')
		result = ft_base(number, trail->format);
	else
		result = ft_base(number, 10);
	result = ft_apply_flag(result, trail);
	result = ft_set_length(trail, result); // Number of digits to print INSIDE the field
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
}
