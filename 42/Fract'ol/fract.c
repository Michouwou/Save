/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:15:46 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/20 16:04:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fract(t_core *core, char *set)
{
	if (!ft_strcmp(set, "julia") || !ft_strcmp(set, "mandelbrot"))
	{
		core->set.set = !ft_strcmp("julia", set) ? 2 : 1;
		core->set.iteration = 50;
		core->set.roof = 4.0;
		core->set.zoom = 1.0;
		core->set.colorset = 1;
		core->set.juliaC = z_num(0.3, 0.1);
	}
	else
		help();
}

void	draw_fract(t_core core)
{
	if (core.set.set == 1)
		draw_mandelbrot(core);
	else if (core.set.set == 2)
		draw_julia(core);
}

void	draw_mandelbrot(t_core core)
{
	t_complex	current;
	t_complex	z;
	int			i;
	int			j;
	int			iter;
	double		zoom;

	i = -1;
	mlx_clear_window(core.mlx.core, core.mlx.win);
	zoom = core.set.zoom;
	while (++i < core.mlx.width)
	{
		j = -1;
		while (++j < core.mlx.height)
		{
			iter = -1;
			current = z_num(zoom * -2.1 + (zoom * 2.7 / core.mlx.width * i),
					zoom * -1.2 + (zoom * 2.4 / core.mlx.height * j));
			z = z_num(0.0, 0.0);
			while (++iter < core.set.iteration && z_mod(z) < core.set.roof)
				z = z_add(z_pow(z, 2), current);
			if (iter == core.set.iteration)
				mlx_pixel_put(core.mlx.core, core.mlx.win, i, j, 0xFFFFFF);
		}
	}
}

void	draw_julia(t_core core)
{
	t_complex	z;
	int			i;
	int			j;
	int			iter;
	double		zoom;

	zoom = core.set.zoom;
	i = -1;
	mlx_clear_window(core.mlx.core, core.mlx.win);
	while (++i < core.mlx.width)
	{
		j = -1;
		while (++j < core.mlx.height)
		{
			iter = -1;
			z = z_num(-1.25 * zoom + (zoom * 3. / core.mlx.width * i), -1.5 * zoom + (zoom * 3. / core.mlx.height * j));
			while (++iter < core.set.iteration && z_mod(z) < core.set.roof)
				z = z_add(z_pow(z, 2), core.set.juliaC);
			if (iter == core.set.iteration)
				mlx_pixel_put(core.mlx.core, core.mlx.win, i, j, 0xFFFFFF);
		}
	}
}
