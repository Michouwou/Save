/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:53:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 11:51:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Bon faut revoir l'affichage des floats, ex :
**%#f --> 255 ne fonctionne pas
**%f  --> ne fonctionne pas non plus...
*/

#include "libftprintf.h"


void	ft_call_float(long double number, T_LIST *trail, char **print)
{
	char	*result;

	number = ft_float_apply_mod(trail, number);
	result = ft_conv_float(number, (trail->accuracy != -1) ?
			trail->accuracy : 6);
	if (trail->format == 'e' || trail->format == 'E')
		result = ft_conv_exp(ft_strnew(2), number, trail);
	if (trail->format == 'E')
		ft_strtoupper(result);
	result = ft_set_width(result, trail);
	result = ft_apply_flag(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
}
