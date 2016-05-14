/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:41:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/13 16:06:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	ret;
	short	tmp;
	short	neg;

	tmp = 0;
	ret = 0;
	while (str[tmp] == ' ' || str[tmp] == '\t' || str[tmp] == '\n' ||
			str[tmp] == '\r' || str[tmp] == '\v' || str[tmp] == '\f')
		++tmp;
	neg = (str[tmp] == '-') ? 1 : 0;
	tmp = (str[tmp] == '-' || str[tmp] == '+') ? tmp + 1 : tmp;
	--tmp;
	while (str[++tmp] && ft_isdigit(str[tmp]))
		ret = (ret * 10) + ((int)(str[tmp] - 48));
	if ((!neg && (ret > 2147483647 || ret < 0)) || (neg &&
				(ret > 2147483648 || ret < 0)))
		ret = 0;
	return (neg ? -1 * ret : ret);
}
