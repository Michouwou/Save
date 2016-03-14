/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:28:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 13:27:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths)
{
	int		link;
	t_path	*tmp;
	t_path	*result;

	tmp = actual_path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_path(room);
	result = NULL;
	link = 0;
	while (room->links[link]->name != NULL)
	{
		tmp = ft_build_path(room->links[link], actual_path, all_paths);
		if (ft_path_is_free(tmp, all_paths))
			result = ft_min_path(tmp, result);
		link++;
	}
	return (result);
}
