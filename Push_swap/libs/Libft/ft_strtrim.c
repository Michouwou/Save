/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 18:13:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char*)s;
	i = 0;
	while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\n')
		i++;
	if (i == (int)ft_strlen(tmp))
	{
		tmp = ft_strnew(0);
		if (tmp == NULL)
			return (NULL);
		return (tmp);
	}
	j = ft_strlen(tmp) - 1;
	while (tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n')
	{
		j--;
	}
	j++;
	tmp = ft_strsub(tmp, i, j - i);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
