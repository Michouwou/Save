/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/11/28 16:35:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	i = 0;
	while (tmp1[i] == tmp2[i] && tmp1[i] != '\0' && tmp2[i] != '\0' &&
			i < (int)n)
		i++;
	if (tmp1[i] == '\0' && i < (int)n)
		return (-1 * tmp2[i]);
	if (tmp2[i] == '\0' && i < (int)n)
		return (tmp1[i]);
	if (i == (int)n)
		return (tmp1[i - 1] - tmp2[i - 1]);
	if (i < (int)n)
		return (tmp1[i] - tmp2[i]);
	return (0);
}
