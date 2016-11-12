/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/10/09 15:44:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	ft_count_figures(int nb)
{
	int		i;
	char	j;

	i = 1;
	j = nb < 0 ? 1: 0;
	while ((-nb / 10 <= i && i <= nb / 10) || (-nb / 10 >= i && i >= nb / 10))
	{
		i *= 10;
		j++;
	}
	return (j);
}

char		*ft_itoa(int nb)
{
	long		i;
	int			j;
	long		buf;
	char		*ret;

	buf = nb;
	ret = ft_strnew(ft_count_figures(buf) + 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = (buf < 0) ? '-' : '0';
	j = (buf < 0) ? 1 : 0;
	buf = (buf < 0) ? -buf : buf;
	i = 1;
	while (i * 10 < buf)
		i *= 10;
	while (i != 0)
	{
		ret[j] = (buf / i) + 48;
		buf %= i;
		i /= 10;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
