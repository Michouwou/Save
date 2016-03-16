/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 15:29:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*increase_tab(char *result, char *to_add)
{
	char	*ret;
	int		i;
	int		j;

	ret = ft_strnew((ft_strlen(result) + ft_strlen(to_add)) + 1);
	i = 0;
	j = 0;
	while (result[j])
	{
		ret[j] = result[j];
		j++;
	}
	ret[j++] = '\n';
	while (to_add[i])
	{
		ret[j] = to_add[i];
		i++;
		j++;
	}
	return (ret);
}

char		**ft_read_file(int fd)
{
	char	*result;
	char	*tmp;
	char	**return_string_tab;

	get_next_line(fd, &result);
	while (get_next_line(fd, &tmp) == 1)
	{
		result = increase_tab(result, tmp);
		tmp = NULL;
	}
	return_string_tab = ft_strsplit(result, '\n');
	return (return_string_tab);
}
