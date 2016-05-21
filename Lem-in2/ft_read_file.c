/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/16 16:11:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		result = ft_strjoin(result, "\n");
		result = ft_strjoin(result, tmp);
		i = 1;
	}
	if (!i)
		return (NULL);
	return_string_tab = ft_strsplit(result, '\n');
	return (return_string_tab);
}
