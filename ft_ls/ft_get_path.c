/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 22:51:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 18:12:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_path(char *super_path, t_data *sub_data)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(super_path) + ft_strlen(sub_data->name) + 1);
	ft_strcpy(tmp, super_path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, sub_data->name);
	sub_data->path = tmp;
}
