/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 09:49:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 10:18:42 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color_pad(int sum)
{
	if (sum / 2 <= 0)
		return (0x0990000);
	if (sum / 2 <= 5)
		return (0x0660099);
	if (sum / 2 <= 10)
		return (0x0333366);
	if (sum / 2 <= 15)
		return (0x033CC33);
	if (sum / 2 >= 15)
		return (0x00033FF);
}

int		ft_abs(int num)
{
	return (num >= 0 ? num : -num);
}

void	ft_draw_line(int p1[], int p2[], t_mlx *mlx_dat)
{
	double	coeff;

	coeff = 0.0;
	if (p2[0] >= p1[0])
	{
		if (p2[1] - p1[1] <= 0 && p1[1] - p2[1] >= p2[0] - p1[0])
			while (p1[1] != p2[1])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p2[0] - p1[0]) / (double)(p1[1] - p2[1]);
				if (coeff >= 0.5)
				{
					p1[0]++;
					coeff -= 1.0;
				}
				p1[1]--;
			}
		else if (p2[1] - p1[1] <= 0 && p1[1] - p2[1] <= p2[0] - p1[0])
			while (p1[0] != p2[0])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p1[1] - p2[1]) / (double)(p2[0] - p1[0]);
				if (coeff >= 0.5)
				{
					p1[1]--;
					coeff -= 1.0;
				}
				p1[0]++;
			}
		else if (p2[1] - p1[1] >= 0 && p2[1] - p1[1] <= p2[0] - p1[0])
			while (p1[0] != p2[0])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
				if (coeff >= 0.5)
				{
					p1[1]++;
					coeff -= 1.0;
				}
				p1[0]++;
			}
		else if (p2[1] - p1[1] >= 0 && p2[1] - p1[1] >= p2[0] - p1[0])
			while (p1[1] != p2[1])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p2[0] - p1[0]) / (double)(p2[1] - p1[1]);
				if (coeff >= 0.5)
				{
					p1[0]++;
					coeff -= 1.0;
				}
				p1[1]++;
			}
	}
	else if (p2[0] < p1[0])
	{
		if (p2[1] - p1[1] <= 0 && p1[1] - p2[1] >= p1[0] - p2[0])
			while (p1[1] != p2[1])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p1[0] - p2[0]) / (double)(p1[1] - p2[1]);
				if (coeff >= 0.5)
				{
					p1[0]--;
					coeff -= 1.0;
				}
				p1[1]--;
			}
		else if (p2[1] - p1[1] <= 0 && p1[1] - p2[1] <= p1[0] - p2[0])
			while (p1[0] != p2[0])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p1[1] - p2[1]) / (double)(p1[0] - p2[0]);
				if (coeff >= 0.5)
				{
					p1[1]--;
					coeff -= 1.0;
				}
				p1[0]--;
			}
		else if (p2[1] - p1[1] >= 0 && p2[1] - p1[1] <= p1[0] - p2[0])
			while (p1[0] != p2[0])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p2[1] - p1[1]) / (double)(p1[0] - p2[0]);
				if (coeff >= 0.5)
				{
					p1[1]++;
					coeff -= 1.0;
				}
				p1[0]--;
			}
		else if (p2[1] - p1[1] >= 0 && p2[1] - p1[1] >= p1[0] - p2[0])
			while (p1[1] != p2[1])
			{
				mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
				coeff += (double)(p1[0] - p2[0]) / (double)(p2[1] - p1[1]);
				if (coeff >= 0.5)
				{
					p1[0]--;
					coeff -= 1.0;
				}
				p1[1]++;
			}
	}
	mlx_pixel_put(mlx_dat->core, mlx_dat->win, p1[0], p1[1], ft_get_color_pad(p1[2] + p2[2]));
}
