/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/05 11:30:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		final_loop(char *str, int neg, int *ret)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		*ret *= 10;
		*ret += (int)(str[i] - 48);
		i++;
	}
	if (neg == 1)
		*ret *= -1;
}

static char		*is_neg(char *str, int *neg)
{
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			*neg = 1;
		str++;
	}
	return (str);
}

static char		*check_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0 && ft_isdigit(str[i]))
		i++;
	return (ft_strsub(str, 0, i));
}

static char		*ft_strtrim_atoi(char const *s)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char*)s;
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\n' ||
			tmp[i] == '\f' || tmp[i] == '\r' || tmp[i] == '\v')
		i++;
	if (i == (int)ft_strlen(tmp))
		return (ft_strnew(0));
	j = ft_strlen(tmp) - 1;
	while (tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n' ||
			tmp[i] == '\f' || tmp[i] == '\r' || tmp[i] == '\v')
		j--;
	j++;
	return (tmp + i);
}

int				ft_atoi(const char *s)
{
	char	*tmp;
	int		neg;
	int		ret;

	neg = 0;
	tmp = (char*)s;
	ret = 0;
	tmp = ft_strtrim_atoi(tmp);
	tmp = is_neg(tmp, &neg);
	tmp = check_valid(tmp);
	final_loop(tmp, neg, &ret);
	free(tmp);
	return (ret);
}
