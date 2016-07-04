/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 19:02:59 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0' && s[i] != '\200')
	{
		if (s[i] != c && s[i] != '\0')
		{
			k++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] != '\0')
			i++;
	}
	return (k);
}

static int	count_char(char *str, char c)
{
	char	*tmp;

	tmp = str;
	while (*tmp != c && *tmp != 0)
		tmp++;
	return (tmp - str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		k;
	char	*tmp;
	char	**ret;
	char	**retmp;

	tmp = (char*)s;
	k = count_words(tmp, c);
	if (!s)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (k + 1));
	retmp = ret;
	if (ret == NULL)
		return (NULL);
	while (*tmp != '\0')
	{
		while (*tmp == c && *tmp != '\0')
			tmp++;
		if (*tmp != '\0')
			*ret++ = ft_strsub(tmp, 0, count_char(tmp, c));
		tmp = tmp + count_char(tmp, c);
	}
	*ret = NULL;
	return (retmp);
}
