/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 17:27:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpa;
	unsigned char	*tmpb;

	tmpa = (unsigned char*)dst;
	tmpb = (unsigned char*)src;
	if (dst > src)
	{
		tmpa = tmpa + len;
		tmpb = tmpb + len;
		while (len)
		{
			*--tmpa = *--tmpb;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
