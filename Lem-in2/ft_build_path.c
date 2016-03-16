/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:28:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 12:10:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	room_does_not_appear(t_room *room, t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	if (tmp)
		while (tmp)
		{
			if (!ft_strcmp(tmp->room->name, room->name))
				return (0);
			tmp = tmp->next;
		}
	return (1);
}

t_path		*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths)
{
	int		link;
	t_path	*tmp;
	t_path	*result;

	printf("Entree dans ft_build_path\n");
	fflush(stdout);
	tmp = actual_path;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_path(room);
	}
	else
	{
		tmp = ft_create_path(room);
		actual_path = tmp;
	}
	result = NULL;
	link = 0;
	printf("Juste avant la boucle dans build_path, room : %s, is_end : %d\n", room->name, room->is_end);
	fflush(stdout);
	if (room->is_end)
		return (result = ft_create_path(room));
	else
		while (room->links[link] && room->links[link]->name != NULL)
		{
			printf("On va rappeler build_path avec : %s\n", room->links[link]->name);
			fflush(stdout);
			if (room_does_not_appear(room->links[link], actual_path))
			{
				tmp = ft_build_path(room->links[link], actual_path, all_paths);
				if (ft_path_is_free(tmp, all_paths))
					result = ft_min_path(tmp, result);
			}
			link++;
		}
	printf("Sortie de ft_build_path\n");
	fflush(stdout);
	return (result);
}
