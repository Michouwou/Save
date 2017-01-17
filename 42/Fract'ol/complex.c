/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:48:47 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/17 22:20:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	z_num(double x, double y)
{
	t_complex z;

	z.real = x;
	z.imaginary = y;
	return (z);
}

t_complex	z_add(t_complex z1, t_complex z2)
{
	return (z_num(z1.real + z2.real, z1.imaginary + z2.imaginary));
}

int			z_mod(t_complex z)
{
	return (z.real * z.real + z.imaginary * z.imaginary);
}

t_complex	z_pow(t_complex z, int pow)
{
	t_complex res;

	res = z_num(z.real, z.imaginary);
	while (pow > 1)
	{
		res.real = res.real * z.real - res.imaginary * z.imaginary;
		res.imaginary = res.real * z.imaginary + res.imaginary * z.real;
		pow--;
	}
	return (res);
}
