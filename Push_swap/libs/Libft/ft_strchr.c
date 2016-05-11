/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/11/25 16:13:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	wanted;
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	wanted = (char)c;
	tmp = (char *)s;
	while (i <= size)
	{
		if (tmp[i] == wanted)
			return (&(tmp[i]));
		i++;
	}
	return (NULL);
}
