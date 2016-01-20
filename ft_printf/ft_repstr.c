/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:06:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 14:24:28 by mlevieux         ###   ########.fr       */
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
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrlen(str) +
			ft_wstrlen(to_insert) - (end - start) + 1);
	ft_wbzero(res, ft_wstrlen(str) + ft_wstrlen(to_insert) - (end - start) + 1);
	while (++i < start)
		res[i] = str[i];
	while (to_insert[++j] != '\0')
		res[i++] = to_insert[j];
	j = end - 1;
	while (str[++j] != '\0')
		res[i++] = str[j];
	res[i] = '\0';
	return (res);
}
