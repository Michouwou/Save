/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:24:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 16:00:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_is_neg(int *k, long double *number, char **final)
{
	if (*number < 0)
	{
		*number = -(*number);
		*k = *k + 1;
		(*final)[0] = '-';
	}
}

char			*ft_conv_float(long double to_print, int accuracy)
{
	char		*final;
	int			k;
	long double	i;

	i = 1.0;
	k = 0;
	final = ft_strnew(310);
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
