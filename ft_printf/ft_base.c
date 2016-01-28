/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:02:17 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 17:59:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static intmax_t	ft_isneg(intmax_t *num, int *k, char *final)
{
	printf("%jd Sa mere\n", *num);
	if (*num < 0)
	{
		printf("Putain!");
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
	char		*final;
	int			k;
	intmax_t	i;
	char		alpha[17];

	if (num < 0 && base != 10)
		ft_error(2);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_bzero(final = (char*)malloc(sizeof(char) * 200), 200);
	ft_isneg(&num, &k, final);
	ft_make_base(&base);
	printf("1A : %d, %d\n", num, base);
	while ((i * (intmax_t)base) < num)
		i = i * (intmax_t)base;
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
	}
	printf("1B : %s\n", final);
	final[k] = 0;
	return (final);
}
