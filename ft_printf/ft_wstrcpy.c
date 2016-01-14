/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:53:45 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 20:55:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t		*ft_wstrcpy(wchar_t *wdst, wchar_t *wsrc)
{
	int i;
	int size;

	size = ft_wstrlen(wsrc);
	i = 0;
	while (i <= size)
	{
		wdst[i] = wsrc[i];
		i++;
	}
	return (wdst);
}
