/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_is_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:33:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 12:19:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_path_is_free(t_path *path, t_path **all_paths)
{
	int		i;
	t_path	*tmp;
	t_path	*cursor;

	tmp = path;
	while (tmp)
	{
		i = 0;
		while (all_paths[i])
		{
			cursor = all_paths[i];
			while (cursor)
			{
				if (!ft_strcmp(cursor->room->name, path->room->name))
					return (0);
				cursor = cursor->next;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}
