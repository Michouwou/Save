/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:02:17 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/10 14:19:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t *ft_base(intmax_t num, int base)
{
	wchar_t		*final;
	int			k;
	intmax_t	i;
	char		alpha[17];

	if (num < 0)
		ft_error(2);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_wbzero(final = (wchar_t*)malloc(sizeof(wchar_t) * 200), 200);
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
