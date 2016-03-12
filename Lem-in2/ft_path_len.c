/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:11:04 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 15:12:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_path_len(t_path *path)
{
	int		len;
	t_path	*tmp;

	tmp = path;
	len = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}