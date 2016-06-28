/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:07:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 14:04:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_mlx *ptr, int nb_lines, int n_per_line, t_line *lines)
{
	int	p1[3];
	int	p2[3];
	int	i;
	int	j;

	i = 0;
	while (i < nb_lines)
	{
		j = 0;
		while (j < n_per_line)
		{
			if (j + 1 < n_per_line)
			{
				p1[0] = lines[i].x[j];
				p1[1] = lines[i].y[j];
				p1[2] = lines[i].z_origin[j];
				p2[0] = lines[i].x[j + 1];
				p2[1] = lines[i].y[j + 1];
				p2[2] = lines[i].z_origin[j + 1];
				ft_draw_line(p1, p2, ptr);
			}
			if (i + 1 < nb_lines)
			{
				p1[0] = lines[i].x[j];
				p1[1] = lines[i].y[j];
				p1[2] = lines[i].z_origin[j];
				p2[0] = lines[i + 1].x[j];
				p2[1] = lines[i + 1].y[j];
				p2[2] = lines[i + 1].z_origin[j];
				ft_draw_line(p1, p2, ptr);
			}
			j++;
		}
		i++;
	}
}
