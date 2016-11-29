/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/13 14:15:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	tmp = (char*)s;
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\n')
		i += 1;
	j = ft_strlen(tmp) - 1;
	k = j;
	while (tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n')
		j -= 1;
	if (tmp == NULL || j == 0)
		return (NULL);
	return (i == 0 && j == k ? tmp : ft_strsub(tmp, i, j - i + 1));
}
