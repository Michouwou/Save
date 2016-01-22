/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:50:44 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/22 11:27:40 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_wstrset(wchar_t *wstr, int len, char c)
{
	int i;

	i = 0;
	while (i <= len)
	{
		wstr[i] = c;
		i++;
	}
	printf("\t\t\tOn va sortir de wstrset\n");
	NOW
	return (wstr);
}
