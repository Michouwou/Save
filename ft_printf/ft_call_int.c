/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:02:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 15:45:51 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_int(intmax_t number, T_LIST *trail, wchar_t **print)
{
	wchar_t	*result;

	printf("\tEntree call_int\n");
	NOW
	number = ft_int_apply_mod(trail, number);
	printf("\tMod_int OK\n");
	NOW
	if (trail->format != 'd' && trail->format != 'D' && trail->format != 'i')
		result = ft_base(number, trail->format);
	else
		result = ft_base(number, 10);
	printf("\tInt base OK\n");
	NOW
	result = ft_set_length(trail, result); // Number of digits to print INSIDE the field
	printf("\tlength_int OK\n");
	NOW
	result = ft_set_width(result, trail);
	printf("\tWidth_int OK, width = %d, length = %d, format = %c, start = %d, end = %d\n", trail->width, trail->accuracy, trail->format, trail->start_index, trail->end_index);
	NOW
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	printf("\tAffectation OK, print = %S\n", *print);
	NOW
}
