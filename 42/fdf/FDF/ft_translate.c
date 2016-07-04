/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:10:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 10:42:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate_x(t_mlx *ptr, int sense)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			if (sense == 1)
				ptr->map[i].x[j] += 20;
			else if (sense == -1)
				ptr->map[i].x[j] -= 20;
			j++;
		}
		i++;
	}
}

void	ft_translate_y(t_mlx *ptr, int sense)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			if (sense == 1)
				ptr->map[i].y[j] += 20;
			else if (sense == -1)
				ptr->map[i].y[j] -= 20;
			j++;
		}
		i++;
	}
}
