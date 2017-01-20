/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:29:48 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/20 16:12:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_core	*init_core(void)
{
	t_core *core;

	core = (t_core*)ft_memalloc(sizeof(t_core));
	core->mlx.width = 800;
	core->mlx.height = 650;
	return (core);
}

static int		key_events(int keycode, t_core *core)
{
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		core->set.zoom -= 0.1;
	else if (keycode == 125)
		core->set.zoom += 0.1;
	else if (keycode == 67)
		core->set.juliaC = z_add(core->set.juliaC, z_num(0.0, 0.01));
	else if (keycode == 75)
		core->set.juliaC = z_add(core->set.juliaC, z_num(0.0, -0.01));
	else if (keycode == 78)
		core->set.juliaC = z_add(core->set.juliaC, z_num(0.01, 0.0));
	else if (keycode == 69)
		core->set.juliaC = z_add(core->set.juliaC, z_num(-0.01, 0.0));
	draw_fract(*core);
	return (0);
}

static int	mouse_events(int keycode, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		core->set.zoom += 0.1;
	else if (keycode == 5)
		core->set.zoom -= 0.1;
	draw_fract(*core);
	return (0);
}

void		help(void)
{
	write(1, "./fractol [-width num] [-heigth num] set_name\n", 46);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_core *core;

	if (argc < 2)
		help();
	core = init_core();
	while (*(++argv))
	{
		if (!ft_strcmp("-width", *argv))
			core->mlx.width = atoi(*(++argv));
		else if (!ft_strcmp("-height", *argv))
			core->mlx.height = atoi(*(++argv));
		else
			set_fract(core, *argv);
	}
	core->mlx.core = mlx_init();
	core->mlx.win = mlx_new_window(core->mlx.core, core->mlx.width,
			core->mlx.height, "Fract'ol");
	draw_fract(*core);
	mlx_key_hook(core->mlx.win, key_events, core);
	mlx_mouse_hook(core->mlx.win, mouse_events, core);
	mlx_loop(core->mlx.core);
	return (0);
}
