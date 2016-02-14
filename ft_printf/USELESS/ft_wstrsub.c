/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:25:46 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 17:12:09 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

wchar_t *ft_wstrnew(size_t len);

wchar_t	*ft_wstrsub(wchar_t const *ws, unsigned int start, size_t len)
{
	int		i;
	wchar_t	*wstr;

	wstr = ft_wstrnew(len);
	i = 0;
	if (wstr == NULL)
		return (NULL);
	while (i < (int)len && ws[i] != 0)
	{
		wstr[i] = ws[start + i];
		i++;
	}
	return (wstr);
}
