/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:40:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 18:25:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_set_width(wchar_t *result, T_LIST *trail)
{
	int i;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != 0)
		i++;
	if (trail->width > ft_wstrlen(result))
	{
		if (!(trail->minus))
		{
			if (trail->z_pad && !(trail->accuracy && trail->type == 'd'))
				result = ft_repstr(result, i, i,
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result)),
					trail->width - ft_wstrlen(result), '0'));
			else
				result = ft_repstr(result, i, i,
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result)),
					trail->width - ft_wstrlen(result), ' '));
		}
		else
			result = ft_repstr(result, ft_wstrlen(result), ft_wstrlen(result),
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result)),
					trail->width - ft_wstrlen(result), ' '));
	}
	return (result);
}
