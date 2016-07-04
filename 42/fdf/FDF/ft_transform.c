/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:36:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 10:23:40 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// max[0] = x_max
// max[1] = y_max

void	ft_rotate_z(t_mlx *ptr, int code)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			ptr->map[i].x[j] = (ptr->map[i].x[j] * cos(0.10 * code)) - (ptr->map[i].y[j] * sin(0.10 * code));
			ptr->map[i].y[j] = (ptr->map[i].x[j] * sin(0.10 * code)) + (ptr->map[i].y[j] * cos(0.10 * code));
			j++;
		}
		i++;
	}
}

void	ft_rotate_x(t_mlx *ptr, int code)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			ptr->map[i].y[j] = (ptr->map[i].y[j] * cos(0.10 * code)) - (ptr->map[i].z[j] * sin(0.10 * code));
			ptr->map[i].z[j] = (ptr->map[i].y[j] * sin(0.10 * code)) + (ptr->map[i].z[j] * cos(0.10 * code));
			j++;
		}
		i++;
	}
}

void	ft_rotate_y(t_mlx *ptr, int code)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->nb_lines)
	{
		j = 0;
		while (j < ptr->n_per_line)
		{
			ptr->map[i].x[j] = (ptr->map[i].x[j] * cos(0.10 * code)) + (ptr->map[i].z[j] * sin(0.10 * code));
			ptr->map[i].z[j] = (ptr->map[i].x[j] * -sin(0.10 * code)) + (ptr->map[i].z[j] * cos(0.10 * code));
			j++;
		}
		i++;
	}
}

void	ft_transform(t_line *lines, int nb_line, int n_per_line)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < n_per_line)
		{
			lines[i].x[j] = lines[i].x[j] * ((WIN_W - 400) / n_per_line) + 200;
			lines[i].y[j] = lines[i].y[j] * ((WIN_H - 200) / nb_line) + 50;
			lines[i].z[j] *= 5;
			j++;
		}
		i++;
	}
}
