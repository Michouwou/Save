/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:50:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 16:42:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_call_pointer(unsigned long pointer, T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	state_value = 1;
	result = ft_base(pointer, 16);
	if (pointer > 0)
		trail->accuracy--;
	result = ft_set_length(trail, result);
	result = ft_repstr(result, 0, 0, "0x");
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}
