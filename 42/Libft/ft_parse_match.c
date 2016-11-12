/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:58:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/12 12:14:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#define P(m) printf(m);fflush(stdout);

static char	*ft_get_char_class(char **str)
{
	char	*class;
	int		size;

	size = ft_strlen(*str) - ft_strlen(ft_strchr(*str, ']')) - 1;
	class = ft_strnew(size + 1);
	ft_strncpy(class + 1, (*str + 1), size);
	*str += size + 1;
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
		write(1, "1", 1);
		if (*tmpb == '[')
		{
			class = ft_get_char_class(&tmpb);
			if (ft_strlen(class) >= !class[0] && !ft_strchr(tmpb, *(tmpa++)))
				return (0);
			while (class[0] && ft_strchr(class, *tmpa))
				++tmpa;
		write(1, "2", 1);
		}
		else if (*tmpb == '*' && !antislash)
		{
			while (*tmpa && !ft_parse_match(tmpb + 1, tmpa))
				++tmpa;
		write(1, "3", 1);
			return (*tmpa ? 1 : 0);
		}
		else if (antislash || *tmpa == '\\')
			antislash = antislash ? 0 : 1;
		else if (*tmpb != *tmpa)
			return (0);
		else if (*tmpa)
			++tmpa;
		++tmpb;
		write(1, "4", 1);
		if (class != NULL  && ft_strlen(class) >= 1)
			free(class);
		class = NULL;
		write(1, "5", 1);
	}
	return (1);
}
