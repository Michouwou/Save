/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:02:17 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:16:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_isneg(intmax_t *num, int *k, wchar_t *final)
{
	if (*num < 0)
	{
		*num = *num - 1;
		*k = 1;
		final[0] = '-';
	}
}

static void ft_make_base(int *base)
{
	if (*base == 'o' || *base == 'O')
		*base = 8;
	if(*base == 'x' || *base == 'X')
		*base = 16;
	if (*base == 'b')
		*base = 2;
}

wchar_t 	*ft_base(intmax_t num, int base)
{
	wchar_t		*final;
	int			k;
	intmax_t	i;
	char		alpha[17];

	if (num < 0 && base != 10)
		ft_error(2);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_wbzero(final = (wchar_t*)malloc(sizeof(wchar_t) * 200), 200);
	ft_isneg(&num, &k, final);
	ft_make_base(&base);
	while ((i * (intmax_t)base) < num)
		i = i * (intmax_t)base;
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
	}
	final[k] = 0;
	return (final);
}
