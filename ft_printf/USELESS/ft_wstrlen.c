/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:03:09 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/22 14:57:59 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_wstrlen(wchar_t *wstring)
{
	int 	i;
	wchar_t *tmp;

	i = 0;
	tmp = wstring;
	while (*(wstring + i) != 0x000 /*&& wstring[i + 1] != 0*/)
	{
		i++;
	}
	printf("\t\t\tBon c'est pas wstrlen ... i = %zd\n", (size_t)i);
	NOW
	return (i);
}
