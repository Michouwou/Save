/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:06:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 15:40:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_repstr(wchar_t *str, int start, int end, wchar_t *to_insert)
{
	wchar_t	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	printf("\t\tEntree dans repstr, start = %d, end = %d\n", start, end);
	NOW
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrlen(str) +
			ft_wstrlen(to_insert) - (end - start) + 1);
	printf("\t\tRes = %S, taille = %d\n", res, ft_wstrlen(str) +
			ft_wstrlen(to_insert) - (end - start) + 1);
	printf("\t\tTaille to_insert = %d\n", ft_wstrlen(to_insert));
	NOW
	ft_wbzero(res, ft_wstrlen(str) + ft_wstrlen(to_insert) - (end - start) + 1);
	printf("\t\tbzero OK, str = %S\n", str);
	NOW
	while (++i < start)
		res[i] = str[i];
	printf("\t\tici i = %d, res = %S\n", i, res);
	NOW
	while (to_insert[++j] != '\0')
		res[i++] = to_insert[j];
	j = end - 1;
	printf("\t\tici j = %d\n", j);
	NOW
	while (str[++j] != '\0')
		res[i++] = str[j];
	res[i] = '\0';
	printf("\t\tRes = %S\n", res);
	NOW
	return (res);
}
