/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:15:18 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/16 09:36:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

void	ft_display(t_superform *solution)
{
	int		y;
	int		x;
	int		i;
	int		len;

	y = -1;
	len = ft_find_square_len(solution);
	while (++y < len)
	{
		x = -1;
		while (++x < len)
		{
			i = -1;
			while (solution->points[++i].id_form != -1)
				if (solution->points[i].x == x)
					if (solution->points[i].y == y)
						break ;
			if (solution->points[i].id_form <= 0)
				ft_putchar('.');
			else
				ft_putchar((char)(solution->points[i].id_form + 64));
		}
		ft_putchar('\n');
	}
}
