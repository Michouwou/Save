/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 16:48:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strjoin_free(char *str1, char *str2, int code)
{
	int		cursor[2];
	int		tmp[2];
	char	*result;

	cursor[0] = 0;
	cursor[1] = 0;
	tmp[0] = ft_strlen(str1);
	tmp[1] = ft_strlen(str2);
	result = ft_strnew(tmp[0] + tmp[1]);
	while (cursor[0] < tmp[0])
	{
		result[cursor[0]] = str1[cursor[0]];
		++cursor[0];
	}
	while (cursor[1] < tmp[1])
	{
		result[cursor[0] + cursor[1]] = str2[cursor[1]];
		++cursor[1];
	}
	result[cursor[0] + cursor[1]] = 0;
	free(code == 1 || code == 3 ? str1 : NULL);
	free(code == 2 || code == 3 ? str2 : NULL);
	return (result);
}

char		**ft_read_file(int fd)
{
	char	*result;
	char	*tmp;
	int		i;
	char	**return_string_tab;

	tmp = NULL;
	result = ft_strnew(1);
	i = 0;
	while (get_next_line(fd, &tmp) == 1)
	{
		if (i == 0 && (!tmp[0] || !ft_is_number(tmp)))
			ft_block("Your file does not begin with the number of ants");
		result = ft_strjoin_free(result, "\n", 1);
		result = ft_strjoin_free(result, tmp, 3);
		i = 1;
	}
	if (!i)
		return (NULL);
	return_string_tab = ft_strsplit(result, '\n');
	free(result);
	return (return_string_tab);
}
