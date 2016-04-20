/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:12:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 14:58:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_parse_date(time_t time, t_data **data)
{
	char	**date;
	char	*tmp;
	int		i;

	date = ft_strsplit(ctime(&time), ' ');
	(*data)->date_mon = ft_strdup(date[1]);
	(*data)->date_num = ft_strdup(date[2]);
	tmp = ft_strdup(date[3]);
	i = 0;
	while (date[i])
		free(date[i++]);
	free(date);
	date = ft_strsplit(tmp, ':');
	free(tmp);
	(*data)->date_hour = ft_strnew(5);
	ft_strcpy((*data)->date_hour, date[0]);
	(*data)->date_hour[2] = ':';
	ft_strcpy((*data)->date_hour + 3, date[1]);
	i = 0;
	while (date[i])
		free(date[i++]);
	free(date);
}
