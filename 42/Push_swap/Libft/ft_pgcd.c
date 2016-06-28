/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:17:32 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/15 12:27:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pgcd(int nb1, int nb2)
{
	int c;

	if (nb1 == 0)
		return (nb2);
	if (nb2 == 0)
		return (nb1);
	if (nb1 < nb2)
		ft_swap(&nb1, &nb2);
	while (nb2 != 0)
	{
		c = nb2;
		nb2 = nb1 % nb2;
		nb1 = c;
	}
	ft_topos(&nb1);
	return (nb1);
}
