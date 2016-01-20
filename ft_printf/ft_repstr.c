/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:06:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 18:44:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_repstr(wchar_t *str, int start, int end, wchar_t *to_insert)
{
	wchar_t	*res;
	int		i;
	int		j;

	i = 0;
	j = -1;
	printf("\t\tEntree dans repstr, start = %d, end = %d\n", start, end);
	NOW
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrlen(str) +
			ft_wstrlen(to_insert) - (end - start) + 2);
	printf("\t\tRes = %S, taille = %d\n", res, ft_wstrlen(str) +
			ft_wstrlen(to_insert) - (end - start) + 1);
	printf("\t\tTaille to_insert = %d\n", ft_wstrlen(to_insert));
	NOW
	ft_wbzero(res, ft_wstrlen(str) + ft_wstrlen(to_insert) - (end - start) + 1);
//	printf("\t\tbzero OK, str = %S\n", str);
//	NOW
	while (i < start)
	{
		res[i] = str[i];
		i++;
	}
	while (++j < ft_wstrlen(to_insert))
		res[i++] = to_insert[j];
	j = end;
	while (str[j] != 0)
	{
		res[i] = str[j];
		i++;
		j++;
	}
	printf("\t\tI = %d\n", i);
	NOW
	res[i] = 0;
	return (res);
}
