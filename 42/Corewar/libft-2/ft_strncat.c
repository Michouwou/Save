/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/04 19:52:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t tmp;
	size_t i;

	i = 0;
	tmp = ft_strlen(s1);
	while (i < n)
	{
		s1[tmp + i] = s2[i];
		i++;
	}
	s1[tmp + i] = 0;
	return (s1);
}
