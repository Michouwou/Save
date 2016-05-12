/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 14:14:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;

	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
	{
		result = (char*)malloc(1);
		return (result = "");
	}
	result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) - 1));
	if (result)
	{
		i = -1;
		while (++i < (int)ft_strlen(s1) && s1[i] != '\0')
			result[i] = s1[i];
		while ((i - ft_strlen(s1)) < ft_strlen(s2)
				&& s2[ft_strlen(s2) - 1] != '\0')
		{
			result[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		result[i] = '\0';
	}
	else
		result = (NULL);
	return (result);
}
