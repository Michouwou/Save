/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:07:53 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/18 19:11:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// Pour le debugg, a retirer
# include <stdio.h>

struct s_complex
{
	double	real;
	double	imaginary;
};

struct s_mlx
{
	void	*core;
	void	*win;
	int		width;
	int		height;
};

struct s_set
{
	int		set;
	int		iteration;
	double	floor;
	double	roof;
	double	zoom;
	int		colorset;
};

typedef struct s_complex	t_complex;
typedef struct s_mlx		t_mlx;
typedef struct s_set		t_set;

struct s_core
{
	t_set	set;
	t_mlx	mlx;
};

typedef struct s_core		t_core;

void		set_fract(t_core *core, char *set);
void		draw_fract(t_core core);
void		help();
t_complex	z_num(double x, double y);
t_complex	z_add(t_complex z1, t_complex z2);
t_complex	z_pow(t_complex z, int pow);
double		z_mod(t_complex z);

#endif
