/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:15:46 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/18 19:20:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fract(t_core *core, char *set)
{
	if (!ft_strcmp(set, "julia") || !ft_strcmp(set, "mandelbrot"))
	{
		core->set.set = 1;
		core->set.iteration = 20;
		core->set.roof = 4.0;
		core->set.zoom = 1.0;
		core->set.colorset = 1;
	}
	else
		help();
}

void	draw_fract(t_core core)
{
	t_complex	current;
	t_complex	z;
	int			i;
	int			j;
	int			iter;

	i = -1;
	mlx_clear_window(core.mlx.core, core.mlx.win);
	while (++i < core.mlx.width)
	{
		j = -1;
		while (++j < core.mlx.height)
		{
			iter = -1;
			current = z_num(-2.1 + ((2.7 / (core.mlx.width * core.set.zoom)) * i),
					-1.2 + ((2.4 / (core.mlx.height * core.set.zoom)) * (core.mlx.height - j)));
			z = z_num(0.0, 0.0);
			while (++iter < core.set.iteration && z_mod(z) < core.set.roof)
				z = z_add(z_pow(z, 2), current);
			if (iter == core.set.iteration)
				mlx_pixel_put(core.mlx.core, core.mlx.win, i, j, 0x000000);
			else
				mlx_pixel_put(core.mlx.core, core.mlx.win, i, j, 0xFFFFFF);
		}
	}
}
