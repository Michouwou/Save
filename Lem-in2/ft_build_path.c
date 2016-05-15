/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:28:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/13 16:50:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	room_does_not_appear(t_room *room, t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	if (tmp && room && room->name)
		while (tmp)
		{
			if (!ft_strcmp(tmp->room->name, room->name))
				return (0);
			tmp = tmp->next;
		}
	return (1);
}

static int	no_option(t_room **rooms, t_path *actual_path)
{
	int i;

	i = 0;
	while (rooms && rooms[i] && rooms[i]->name &&
			!room_does_not_appear(rooms[i], actual_path))
		i++;
	if (rooms && room_does_not_appear(rooms[i], actual_path))
		return (0);
	return (1);
}

static void	erase_last_one(t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	free(tmp->next ? tmp->next : tmp);
	tmp->next = NULL;
}

static int	part_two(t_path **tmp, t_path **actual_path, t_room **room, t_path **all_paths)
{
	*tmp = *actual_path;
	while (*tmp && (*tmp)->next)
		*tmp = (*tmp)->next;
	if (!*tmp)
		*actual_path = ft_create_path(*room);
	else
		(*tmp)->next = ft_create_path(*room);
	if ((*room)->is_end)
	{
		erase_last_one(*actual_path);
		return (1);
	}
	if (!(*room)->is_end && no_option((*room)->links, *actual_path))
	{
		erase_last_one(*actual_path);
		return (2);
	}
	return (-1);
}

t_path		*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths)
{
	t_path	*result;
	t_path	*tmp;
	int		i;

	i = part_two(&tmp, &actual_path, &room, all_paths);
	if (i != -1)
		return (i == 1 ? ft_create_path(room) : NULL);
	result = NULL;
	tmp = NULL;
	while (room->links && room->links[++i] && room->links[i]->name)
	{
		if (room_does_not_appear(room->links[i], actual_path))
			tmp = ft_build_path(room->links[i], actual_path, all_paths);
		if (tmp && ft_path_is_free(tmp, all_paths))
			result = ft_min_path(result, tmp);
		tmp = NULL;
	}
	tmp = ft_create_path(room);
	/*if (result == NULL)
	{
		erase_last_one(actual_path);
		return (NULL);
	}*/
	tmp->next = result;
	result = result ? tmp : NULL;
	erase_last_one(actual_path);
	return (result);
}
