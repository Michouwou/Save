/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:24:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/19 14:34:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_flag(char *format, int location, T_LIST *knot)
{
	int		i;

	i = location + 1;
	while (ft_is_flag(format[i]))
	{
		if (format[i] == '#')
			knot->alternate = 1;
		if (format[i] == '-')
			knot->minus = 1;
		if (format[i] == '+')
			knot->plus = 1;
		if (format[i] == ' ')
			knot->space = 1;
		if (format[i] == '0')
			knot->z_pad = 1;
		i++;
	}
}
