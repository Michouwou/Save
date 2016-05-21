/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 17:38:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*tmpa;
	unsigned char	*tmpb;
	unsigned char	tmpc;

	tmpa = (unsigned char*)dst;
	tmpb = (unsigned char*)src;
	tmpc = (unsigned char)c;
	i = 0;
	while (i < (int)n)
	{
		tmpa[i] = tmpb[i];
		if (tmpb[i] == tmpc)
			break ;
		i++;
	}
	return ((i == (int)n) ? 0 : &dst[i + 1]);
}
