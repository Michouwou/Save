/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:08:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 10:24:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_mlx *ptr, int sense)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			if (sense == 1)
			{
				ptr->map[i].x[j] = ptr->map[i].x[j] * 1.5 - WIN_W / 4;
				ptr->map[i].y[j] = ptr->map[i].y[j] * 1.5 - WIN_H / 4;
			}
			if (sense == -1)
			{
				ptr->map[i].x[j] = ptr->map[i].x[j] / 1.5 + WIN_W / 6;
				ptr->map[i].y[j] = ptr->map[i].y[j] / 1.5 + WIN_H / 6;
			}
			j++;
		}
		i++;
	}
}
