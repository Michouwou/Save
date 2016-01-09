/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_already_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:15:44 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/16 09:37:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		ft_is_already_in(int id, t_superform *data)
{
	int i;

	i = 0;
	while (data->points[i].id_form != -1)
	{
		if (data->points[i].id_form == id)
			return (0);
		i++;
	}
	return (1);
}
