/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:14:07 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/16 18:30:18 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		ft_max(int x, int y)
{
	return ((x >= y) ? x : y);
}

int		ft_min(int x, int y)
{
	return ((x <= y) ? x : y);
}

int		ft_isempty(t_superform *super, int x, int y)
{
	t_point *tmp;

	tmp = super->points;
	while (tmp->id_form != -1)
	{
		if (tmp->x == x)
			if (tmp->y == y)
				return (0);
		tmp++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int i;

	i = -1;
	while (str[++i] != 0)
		ft_putchar(str[i]);
	ft_putchar('\n');
}
