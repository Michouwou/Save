/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:40:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 13:54:34 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_width(char *result, T_LIST *trail)
{
	int i;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != '+' && result[i] != '-' &&
			result[i] != 0 && (trail->type == 'd' || trail->type == 'f'))
		i++;
	if (trail->width > (int)ft_strlen(result))
	{
		if (!(trail->minus))
		{
			if (trail->z_pad && !(trail->accuracy != -1 && trail->type == 'd'))
				result = ft_repstr(result, (result[i] == '+' || result[i] == '-'
					) ? i = i + 1 : i, i,
					ft_strset(ft_strnew(trail->width - ft_strlen(result)),
					trail->width - ft_strlen(result), '0'));
			else
				result = ft_repstr(result, i, i,
					ft_strset(ft_strnew(trail->width - ft_strlen(result)),
					trail->width - ft_strlen(result), ' '));
		}
		else
			result = ft_repstr(result, ft_strlen(result), ft_strlen(result),
				ft_strset(ft_strnew(trail->width - ft_strlen(result)),
				trail->width - ft_strlen(result), ' '));
	}
	return (result);
}
