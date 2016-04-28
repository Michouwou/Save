/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:45:29 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/28 16:57:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_set_length(T_LIST *trail, char *result, int *state_value)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (!ft_strcmp(result, "0") && !trail->accuracy && !trail->alternate)
		return (ft_strnew(1));
	while (result[++j] != 0)
		if (ft_isdigit(result[j]))
			i++;
	i = trail->accuracy - i;
	j = 0;
	while (!ft_isdigit(result[j]) && result[j] != 0)
		j++;
	if (trail->type == 'd' && i > 0)
		result = ft_repstr(result, j, j, ft_strset(ft_strnew(i), i, '0'));
	else if (trail->type == 'S' && trail->accuracy != -1)
		result[trail->accuracy - (trail->accuracy % trail->oct_num)] = 0;
	else if (trail->type == 's')
		result[trail->accuracy] = 0;
	return (result);
}
