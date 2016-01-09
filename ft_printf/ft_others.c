/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:55:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/06 18:57:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void ft_putstring(char *string)
{
	int i;

	i = 0;
	while (string[i] != 0)
	{
		write(1, (string + i), 1);
		i++;
	}
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putoctal(int to_display)
{
	int oct;

	oct = ft_base(to_display, 8);
	ft_putnbr(oct);
}
