/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 09:49:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/19 11:37:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int num)
{
	return (num >= 0 ? num : -num);
}

void	ft_draw_line(int p1[], int p2[], t_mlx *mlx_dat)
{
	double	coeff;

	coeff = 0.0;
	if (p2[1] - p1[1] < 0 && p1[1] - p2[1] > p2[0] - p1[0])
		while (p1[1] != p2[1])
		{
			mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], 0x0FFFFFF);
			coeff += (double)(p2[0] - p1[0]) / (double)(p1[1] - p2[1]);
			if (coeff >= 0.5)
			{
				p1[0]++;
				coeff -= 1.0;
			}
			p1[1]--;
		}
	else if (p2[1] - p1[1] < 0 && p1[1] - p2[1] < p2[0] - p1[0])
		while (p1[0] != p2[0])
		{
			mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], 0x0FFFFFF);
			coeff += (double)(p1[1] - p2[1]) / (double)(p2[0] - p1[0]);
			if (coeff >= 0.5)
			{
				p1[1]--;
				coeff -= 1.0;
			}
			p1[0]++;
		}
	else if (p2[1] - p1[1] > 0 && p2[1] - p1[1] < p2[0] - p1[0])
		while (p1[0] != p2[0])
		{
			mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], 0x0FFFFFF);
			coeff += (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
			if (coeff >= 0.5)
			{
				p1[1]++;
				coeff -= 1.0;
			}
			p1[0]++;
		}
	else if (p2[1] - p1[1] > 0 && p2[1] - p1[1] > p2[0] - p1[0])
		while (p1[1] != p2[1])
		{
			mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], 0x0FFFFFF);
			coeff += (double)(p2[0] - p1[0]) / (double)(p2[1] - p1[1]);
			if (coeff >= 0.5)
			{
				p1[0]++;
				coeff -= 1.0;
			}
			p1[1]++;
		}
	mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], 0x0FFFFFF);
}
