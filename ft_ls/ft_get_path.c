/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 22:51:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:11:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_path(t_data **data, t_data *sub_data)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen((*data)->path) + ft_strlen(sub_data->name));
	ft_strcpy(tmp, (*data)->path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, sub_data->name);
	sub_data->path = tmp;
}
