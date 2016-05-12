/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 15:20:40 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = -1;
	printf("ON ENTRE\n");
	printf("ON ENTRE\n");fflush(stdout);
	if (!s1 && !s2)
		return (NULL);
	result = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!result)
		return (NULL);
	if (s1)
		result = ft_strcat(result, s1);
	printf("Chaine apres s1 : %s\n", result);
	if (s2)
		result = ft_strcat(result, s2);
	printf("Chaine apres s2 : %s\n", result);
	result[ft_strlen(result) + 1] = 0;
	return (result);
}
