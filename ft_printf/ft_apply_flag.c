/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:20:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 15:00:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_apply_flag(char *result, T_LIST *trail)
{
	char t;

	t = trail->format;
	if ((trail->type == 'd' || trail->type == 'f') && (trail->plus ||
				trail->space || result[0] == '-'))
	{
		if (trail->space && ft_isdigit(result[0]) && (t != 'o' && t != 'O' &&
					t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, " ");
		if (trail->plus && ft_isdigit(result[0]) && (t != 'o' && t != 'O' &&
					t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, /*(trail->width >= ft_strlen(result)) ?
						1 */ 0, "+");
	}
	if (trail->alternate)
		result = ft_alternate(result, trail);
	return (result);
}
