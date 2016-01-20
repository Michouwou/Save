/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:24:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:27:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static double	ft_power(long double num, int pow)
{
	if (pow < 0)
		return (1 / ft_power(num, -pow));
	else if (pow == 0)
		return (1);
	else
		return (num * ft_power(num, pow - 1));
}

static void		ft_is_neg(int *k, long double *number, wchar_t **final)
{
	if (*number < 0)
	{
		*number = -(*number);
		*k = *k + 1;
		(*final)[0] = '-';
	}
}

wchar_t			*ft_conv_float(long double to_print, int accuracy)
{
	wchar_t		*final;
	int			k;
	long double	i;

	i = 1.0;
	k = 0;
	final = ft_wstrnew(310);
	while (i < to_print)
		i *= 10;
	ft_is_neg(&k, &to_print, &final);
	while ((i = i / 10) >= 1)
	{
		final[k++] = (int)(to_print / i) + 48;
		to_print = (long double)((intmax_t)to_print % (intmax_t)i) + to_print -
			(intmax_t)to_print;
	}
	final[k++] = (accuracy > 0) ? ',' : 0;
	while (accuracy-- > 0)
	{
		to_print *= 10;
		final[k++] = (intmax_t)to_print + 48;
		to_print = to_print - (intmax_t)to_print;
	}
	return (final);
}
