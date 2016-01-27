/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:48:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 17:40:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static double	ft_power(double num, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (num * ft_power(num, pow - 1));
}

void			ft_round(long double *num, int accuracy)
{
	if (((int)(*num / (1.0 / (10.0 * ((long double)(accuracy) + 1.0)))) % 10) >= 5)
		*num = *num + 1.0 / ft_power(10.0, accuracy);
}
