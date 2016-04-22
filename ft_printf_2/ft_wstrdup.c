/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:58:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 17:20:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

size_t	ft_wstrlen(wchar_t const *wstring);
wchar_t	*ft_wstrnew(size_t len);

wchar_t	*ft_wstrdup(const wchar_t *ws)
{
	int 	i;
	int		size;
	wchar_t	*ret;

	i = 0;
	size = ft_wstrlen(ws);
	ret = ft_wstrnew(size);
	if (ret == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i < size)
	{
		ret[i] = ws[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
