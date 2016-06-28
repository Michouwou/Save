/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_is_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:33:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/13 17:10:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_path_is_free(t_path *path, t_path **all_paths)
{
	int		i;
	t_path	*tmp;
	t_path	*cursor;

	tmp = path;
	while (tmp)
	{
		i = -1;
		while (all_paths[++i])
		{
			cursor = all_paths[i];
			while (cursor)
			{
				if (!ft_strcmp(cursor->room->name, tmp->room->name) &&
						!cursor->room->is_start && !cursor->room->is_end)
					return (0);
				cursor = cursor->next;
			}
		}
		if (tmp->next && tmp->next->room->is_start)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
