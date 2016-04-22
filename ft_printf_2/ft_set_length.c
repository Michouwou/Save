/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 12:57:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_length(T_LIST *trail, char *result)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (result[++j] != 0)
		if (ft_isdigit(result[j]))
			i++;
	i = trail->accuracy - i;
	j = 0;
	while (!ft_isdigit(result[j]) && result[j] != 0)
		j++;
	if (trail->type == 'd' && i > 0)
		result = ft_repstr(result, j, j, ft_strset(ft_strnew(i), i, '0'));
	else if (trail->type == 'S' || trail->type == 'E')
		result[trail->accuracy] = 0;
	return (result);
}
