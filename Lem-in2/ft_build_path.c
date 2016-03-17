/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:28:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/17 11:15:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/**
 * Penser a faire la fonction pour retirer la room du actual path
 **/

static int	room_does_not_appear(t_room *room, t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	if (tmp && room->name)
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
	printf("Entree no_option, rooms[i] ?");
	while (rooms[i] && rooms[i]->name && !room_does_not_appear(rooms[i], actual_path))
		i++;
	printf("In the loop???\n");
	fflush(stdout);
	if (room_does_not_appear(rooms[i], actual_path))
	{
		printf("sortie no_option\n");
		fflush(stdout);
		return (0);
	}
	printf("Sortie no_option\n");
	fflush(stdout);
	return (1);
}

static void	erase_last_one(t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	printf("Nous liberons : %s\n", tmp->next->room->name);
	free(tmp->next);
	tmp->next = NULL;
}

t_path		*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths)
{
	t_path	*result;
	t_path	*tmp;
	int		i;

	printf("Entree dans build, room = %s\n", room->name);
	fflush(stdout);
	tmp = actual_path;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		actual_path = ft_create_path(room);
	else
		tmp->next = ft_create_path(room);
	printf("Actual path updated\n");
	fflush(stdout);
	if (room->is_end)
	{
		erase_last_one(actual_path);
		return (ft_create_path(room));
	}
	printf("WESH\n");
	fflush(stdout);
	if (!room->is_end && no_option(room->links, actual_path))
	{
		erase_last_one(actual_path);
		return (NULL);
	}
	printf("On est pas au bout dude!\n");
	fflush(stdout);
	i = 0;
	result = NULL;
	tmp = NULL;
	while (room->links && room->links[i] && room->links[i]->name)
	{
		printf("On encadre : links[i] =  et room = \n");
		fflush(stdout);
		if (room_does_not_appear(room->links[i], actual_path))
			tmp = ft_build_path(room->links[i], actual_path, all_paths);
		printf("First tmp room : %s\n", (tmp) ? (tmp->room->name) : "NOOO");
		fflush(stdout);
		if (tmp && ft_path_is_free(tmp, all_paths))
			result = ft_min_path(result, tmp);
		i++;
		tmp = NULL;
		printf("It loops\n");
		fflush(stdout);
	}
	tmp = ft_create_path(room);
	if (result == NULL)
		return (NULL);
	tmp->next = result;
	result = tmp;
	erase_last_one(actual_path);
	return (result);
}
