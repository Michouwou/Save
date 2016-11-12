/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:54:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/11 11:12:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"

void		ft_header_check(char **resource, int *line)
{
	char	**name;
	char	**desc;

	name = ft_strplit(resource[0], "\"");
	desc = ft_strplit(resource[1], "\"");
	if (ft_strcmp(ft_strtrim(name[0]), NAME_CMD_STRING ||
		ft_strcmp(ft_strtrim(desc[0]), COMMENT_CMD_STRING)))
		return (0);
	if (ft_strlen(ft_strtrim(name[1])) - 1 > 128 ||
		ft_strlen(ft_strtrim(desc[1])) - 1 > 2048)
		return (0);
	return (1);
}
