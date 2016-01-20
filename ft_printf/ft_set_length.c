/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 14:23:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_set_length(T_LIST *trail, wchar_t *result)
{
	int i;
	int j;

	i = trail->accuracy - ft_wstrlen(result);
	while (!ft_isdigit(result[j]))
		j++;
	if (trail->type == 'd' && trail->accuracy > ft_wstrlen(result))
		result = ft_repstr(result, j, j, ft_wstrset(ft_wstrnew(i), i, '0'));
	else if (trail->type == 'S')
		result[trail->accuracy] = 0;
	return (result);
}
