/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:33:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 17:21:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstring;
	int		i;

	i = 0;
	wstring = (wchar_t*)malloc(sizeof(wchar_t) * size + 1);
	if (wstring == NULL)
		return (NULL);
	while (i < (int)size + 1)
	{
		wstring[i] = 0;
		i++;
	}
	return (wstring);
}
