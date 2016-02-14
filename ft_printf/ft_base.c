/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:02:17 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 14:32:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_isneg(intmax_t *num, int *k, char *final)
{
	if (*num < 0)
	{
		*num = -(*num);
		*k = 1;
		final[0] = '-';
	}
}

static void 	ft_make_base(int *base)
{
	if (*base == 'o' || *base == 'O')
		*base = 8;
	if(*base == 'x' || *base == 'X')
		*base = 16;
	if (*base == 'b')
		*base = 2;
}

char 			*ft_base(intmax_t num, int base)
{
	char			*final;
	int				k;
	intmax_t		i;
	char			alpha[17];

	if (num < 0 && base != 10)
		ft_error(2);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_bzero(final = (char*)malloc(sizeof(char) * 200), 200);
	ft_isneg(&num, &k, final);
	ft_make_base(&base);
	while ((i * base) < num)
		i = i * base;
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
	}
	final[k] = 0;
	return (final);
}
