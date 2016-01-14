/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 19:06:18 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_set_length(T_LIST *trail, wchar_t *result)
{
	int i;

	i = trail->length - ft_wstrlen(result);
	if (trail->type == 'd' && trail->length > ft_wstrlen(result))
		result = ft_repstr(result, 0, 0, ft_wstrset(ft_wstrnew(i), i, '0'));
	else if (trail->type == 'f')
		result = ft_float_set_length(result, trail);
	else if (trail->type == 'S')
		result[trail->length] = 0;
	else if ()
}
