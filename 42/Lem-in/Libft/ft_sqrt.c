/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:40:40 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/15 12:27:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double nb)
{
	double x;
	double y;
	double e;

	e = 0.00001;
	if (nb < 0)
	{
		return (-1);
	}
	x = nb;
	y = 1;
	if (nb == 0)
		return (0);
	while (x < (y - e) || x > (y + e))
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}
