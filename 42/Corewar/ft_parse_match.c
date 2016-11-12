/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:58:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/11 19:03:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_get_char_class(char **str)
{
	char	*class;
	int		size;

	size = ft_strlen(*str) - ft_strlen(ft_strchr(*str, ']'));
	class = ft_strnew(size + 1);
	ft_strncpy(class + 1, *str, size);
	*str += size;
	class[0] = *(*str + 1) == '+' ? 1 : 0;
	if (class[0])
		*str += 1;
	return (class);
}

int			ft_parse_match(char *regex, char *string)
{
	char	*tmpa;
	char	*tmpb;
	char	*class;
	char	antislash;

	tmpa = string;
	tmpb = regex;
	while (*tmpb != 0)
	{
		if (*tmpb == '[')
		{
			class = ft_get_char_class(&tmpb);
			if (!class[0] && !ft_strchr(tmpb, *(tmpa++)))
				return (0);
			while (class[0] && ft_strchr(tmpb, *tmpa))
				++tmpa;
		}
		else if (*tmpb == '*' && !antislash)
		{
			while (*tmpa && !ft_parse_match(tmpb + 1, tmpa))
				++tmpa;
			return (*tmpa ? 1 : 0);
		}
		else if (antislash || *tmpa == '\\')
			antislash = antislash ? 0 : 1;
		else if (*tmpb != *tmpa)
			return (0);
		++tmpa;
		++tmpb;
		if (class)
			free(class);
		class = NULL;
	}
	return (1);
}
