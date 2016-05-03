/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:49:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 17:16:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apply_flag(char *result, T_LIST *trail)
{
	char	t;

	t = trail->format;
	if ((trail->type == 'd' || trail->type == 'f') && (trail->plus ||
				trail->space || result[0] == '-'))
	{
		if (trail->plus && ft_isdigit(result[0]) && (trail->is_signed ||
			trail->type == 'f'))
			result = ft_repstr(result, 0, 0, ft_strdup("+"));
		else if (trail->space && ft_isdigit(result[0]) && trail->is_signed)
			result = ft_repstr(result, 0, 0, ft_strdup(" "));
	}
	return (result);
}
