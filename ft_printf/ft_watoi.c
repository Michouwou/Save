/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:36:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/19 15:17:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		final_loop(wchar_t *wstr, int neg, int *ret)
{
	int i;

	i = 0;
	while (wstr[i] != 0)
	{
		*ret *= 10;
		*ret += (int)(wstr[i] - 48);
		i++;
	}
	if (neg == 1)
		*ret *= -1;
}

static wchar_t	*is_neg(wchar_t *wstr, int *neg)
{
	if (wstr[0] == '-' || wstr[0] == '+')
	{
		if (wstr[0] == '-')
			*neg = 1;
		wstr++;
	}
	return (ft_wstrdup(wstr));
}

static wchar_t	*check_valid(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i] != 0 && ft_isdigit(wstr[i]))
		i++;
	return (ft_wstrdup(ft_wstrsub(wstr, 0, i)));
}

static wchar_t	*ft_wstrtrim_atoi(wchar_t const *ws)
{
	int		i;
	int		j;
	wchar_t	*tmp;

	tmp = (wchar_t*)ws;
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\n' ||
			tmp[i] == '\f' || tmp[i] == '\r' || tmp[i] == '\v')
		i++;
	if (i == (int)ft_wstrlen(tmp))
		return (ft_wstrnew(0));
	j = ft_wstrlen(tmp) - 1;
	while (tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n' ||
			tmp[j] == '\f' || tmp[j] == '\r' || tmp[j] == '\v')
		j--;
	j++;
	tmp = ft_wstrdup(ft_wstrsub(tmp, i, j - i));
	return (tmp);
}

int				ft_watoi(const wchar_t *ws)
{
	wchar_t	*tmp;
	int		neg;
	int		ret;

	neg = 0;
	tmp = (wchar_t*)ws;
	tmp = ft_wstrtrim_atoi(tmp);
	tmp = is_neg(tmp, &neg);
	tmp = check_valid(tmp);
	final_loop(tmp, neg, &ret);
	return (ret);
}
