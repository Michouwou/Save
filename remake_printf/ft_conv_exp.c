/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:51:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 16:14:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv_exp(long double number, T_LIST *trail)
{
	int		i;
	char	*res;

	i = 0;
	while (number >= 10.0 || number <= -10.0)
	{
		number /= 10.0;
		i++;
	}
	while (number < 1.0 && number > -1.0)
	{
		number *= 10.0;
		i--;
	}
	res = ft_itoa(i);
	if (i < 10 && i > -10)
		res = ft_repstr(res, i < 0 ? 1 : 0, i < 0 ? 1 : 0, "0");
	if (i >= 0)
		res = ft_repstr(res, 0, 0, "+");
	res = ft_repstr(res, 0, 0, "e");
	res = ft_repstr(res, 0, 0, ft_conv_float(number, trail->accuracy > 0 ?
				trail->accuracy : 6));
	return (res);
}
