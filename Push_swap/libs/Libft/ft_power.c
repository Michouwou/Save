/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:20:53 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/15 12:27:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(double nb, int pow)
{
	if (pow < 0)
		return (1 / ft_power(nb, -pow));
	else if (pow == 0)
		return (1);
	else
		return (nb * ft_power(nb, pow - 1));
}
