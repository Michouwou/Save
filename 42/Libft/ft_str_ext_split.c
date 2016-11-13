/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ext_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:43:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/13 12:00:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char *ext)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (str[i] != 0 && str[i] != '\200')
	{
		if (ft_strchr(ext, str[i]) && i != 0 && !ft_strchr(str[i - 1]))
			w += 1;
		i += 1;
	}
	return (w);
}

static void	fill(char *actual, char **iter, 

char		**ft_str_ext_split(char *str, char *ext)
{
	char	**res;
	int		nb_w;
	int		k;
	char	*tmp;

	nb_w = count_words(str, ext);
	res = (char **)malloc(sizeof(char *) * (nb_w + 1));
	k = 0;
	while (k < nb_w)
		res[k++] = NULL;
	tmp = str;
	k = 0;
	while (k < nb_w)
	{
		fill(res[k], &tmp, ext);
		k += 1;
	}
	return (res);
}
