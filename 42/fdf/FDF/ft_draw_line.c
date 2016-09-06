/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 09:49:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 09:41:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color_pad(int sum)
{
	if (sum <= 0)
		return (0x4072A4 * (sum != 0 ? sum : 1));
	if (sum <= 2)
		return (0x4068A4 * sum);
	if (sum <= 4)
		return (0x4057A4 * sum);
	if (sum <= 6)
		return (0x4043A4 * sum);
	if (sum <= 8)
		return (0x4A40A4 * sum);
	if (sum <= 10)
		return (0x5B40A4 * sum);
	if (sum <= 15)
		return (0x6140A4 * sum);
	if (sum <= 20)
		return (0x6B40A4 * sum);
	if (sum <= 30)
		return (0x7540A4 * sum);
	return (0x8640A4 * sum);
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
