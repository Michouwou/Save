/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 13:27:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_read_file(int fd)
{
	char	*result;
	char	*tmp;
	char	**return_string_tab;

	result = ft_strnew(1);
	tmp = NULL;
	while (get_next_line(fd, &tmp) == 1)
	{
		result = ft_strjoin(result, "\n");
		result = ft_strjoin(result, tmp);
		free(tmp);
		tmp = NULL;
	}
	return_string_tab = ft_strsplit(result, '\n');
	return (return_string_tab);
}
