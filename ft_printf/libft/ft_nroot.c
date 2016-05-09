/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nroot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:11:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 09:37:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_nroot(double nb, int root)
{
	double x;
	double y;

	if (nb == 0)
		return (0);
	if (root <= 0 || (nb < 0 && (root % 2) == 0))
		return (-1);
	if (nb < 0 && (root % 2) == 1)
		return (-ft_nroot(-nb, root));
	if (root == 2)
		return (ft_sqrt(nb));
	else
	{
		x = ft_nroot(nb, root - 1);
		y = 1;
		while (x - y > 0.00001 || y - x > 0.00001)
		{
			x = (x * (root - 1) + y) / root;
			y = nb / ft_power(x, root - 1);
		}
	}
	return (x);
}
