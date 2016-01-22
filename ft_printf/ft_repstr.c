/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:06:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/22 15:27:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_repstr(wchar_t *str, int start, int end, wchar_t *to_insert)
{
	wchar_t	*res;
	int		i;
	int		j;
	int		tmp;

	tmp = ft_wstrlen(to_insert);
	res = (wchar_t*)malloc(sizeof(wchar_t) * (ft_wstrlen(str) - (end - start) + ft_wstrlen(to_insert) + 2));
	ft_wbzero(res, ft_wstrlen(str) - (end - start) + ft_wstrlen(to_insert) + 1);
	i = 0;
	j = 0;
	printf("\t\tCe serait encore dans repstr???\n");
	NOW
	while (i < start)
	{
		res[i] = str[i];
		i++;
	}
	printf("\t\tPremiere boucle OK, to_insert : %C, soit une tail de %zd\n", to_insert[4], ft_wstrlen(to_insert));
	NOW
	while (j < ft_wstrlen(to_insert))//tmp)
	{
		res[i] = (int)to_insert[j];
		i++;
		j++;
	}
	printf("\t\tDeuxieme boucle OK");
	NOW
	j = end;
	while (str[j] != 0)
	{
		res[i] = (int)str[j];
		j++;
		i++;
	}
	res[i] = 0;
	printf("\t\tSi tu vois ca t'es bon!\n");
	NOW
	return (res);
}
