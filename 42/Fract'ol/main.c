/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:29:48 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/17 21:59:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	 key_events(int keycode, t_core *core)
{
	(void)core;
	(void)keycode;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		help(void)
{
	write(1, "./fractol [-width num] [-heigth num] set_name\n", 46);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_core core;

	if (argc < 2)
		help();
	core.mlx.width = 800;
	core.mlx.height = 650;
	while (*(++argv))
	{
		if (!ft_strcmp("-width", *argv))
			core.mlx.width = atoi(*(++argv));
		else if (!ft_strcmp("-height", *argv))
			core.mlx.height = atoi(*(++argv));
		else
			set_fract(&core, *argv);
	}
	core.mlx.core = mlx_init();
	core.mlx.win = mlx_new_window(core.mlx.core, core.mlx.width,
			core.mlx.height, "Fract'ol");
	draw_fract(core);
	mlx_key_hook(core.mlx.win, key_events, &core);
	mlx_loop(core.mlx.core);
	return (0);
}
