/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:02:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 14:36:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char	*result;

	if (trail->format != 'd' && trail->format != 'D' && trail->format != 'i' && trail->format != 'u' && trail->format != 'U')
		result = ft_base(number, trail->format);
	else
		result = ft_base(number, 10);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail);
	result = ft_set_length(trail, result); // Number of digits to print INSIDE the field
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
}
