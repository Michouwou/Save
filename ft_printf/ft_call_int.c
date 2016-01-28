/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:02:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 18:23:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char	*result;
	int		flag_neg;

	number = ft_int_apply_mod(trail, number);
	if (flag_neg == 1)
		number = -number;
	if (trail->format != 'd' && trail->format != 'D' && trail->format != 'i')
		result = ft_base(number, trail->format);
	else
		result = ft_base(number, 10);
	printf("2 : %s\n", result);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail);
	printf("3 : %s\n", result);
	result = ft_set_width(result, trail);
	printf("4 : %s\n", result);
	result = ft_set_length(trail, result); // Number of digits to print INSIDE the field
	printf("5 : %s\n", result);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
}
