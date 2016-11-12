/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:58:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/12 14:33:17 by mlevieux         ###   ########.fr       */
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

char		*ft_str_reg_chr(const char *s, int c)
{
	char	wanted;
	char	*tmp;
	int		i;
	int		j_dash;
	
	i = -1;
	wanted = (char)c;
	tmp = (char *)s;
	while (tmp[++i] != 0)
	{
		if (tmp[i] == '-')
		{
			j_dash = tmp[i - 1];
			while (++j_dash < tmp[i + 1])
				if (j_dash == wanted)
					return (&(tmp[i]));
		}
		else if (tmp[i] == wanted)
			return (&(tmp[i]));
	}
	return (NULL);
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
		class = NULL;
		if (*tmpb == '[')
		{
			class = ft_get_char_class(&tmpb);
			if (!ft_str_reg_chr(class + 1, *(tmpa++)))
				return (0);
			while (class[0] && ft_str_reg_chr(class + 1, *tmpa))
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
		else if (*tmpa)
			++tmpa;
		++tmpb;
		if (class != NULL  && ft_strlen(class) >= 1)
			free(class);
	}
	return (1);
}
