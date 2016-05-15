/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:28:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/15 12:02:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// cursors[0] pour la grande boucle, cursors[1] pour parcourir les rooms
// et cursors[2] pour savoir si on a au moins un link, cursors[3] au cas
// ou aucun link ne corresponde a une room

static char	**init(int curs[], t_room **tmp_one, t_room **tmp_two, char **args)
{
	curs[3] = 1;
	*tmp_one = NULL;
	*tmp_two = NULL;
	return (ft_strsplit(args[curs[0]], '-'));
}

static void	get_rooms(t_room **rooms, t_room **one, t_room **two, char **link)
{
	int		i;

	i = 0;
	while (rooms[i]->name && !(*one && *two))
	{
		if (!ft_strcmp(rooms[i]->name, link[0]))
			*one = rooms[i];
		if (!ft_strcmp(rooms[i]->name, link[1]))
			*two = rooms[i];
		i++;
	}
}

static int	final_cond(t_room *one, t_room *two, int cursors[], char **links)
{
	free(links[0]);
	free(links[1]);
	if (one && two)
	{
		cursors[2] = 1;
		ft_link_room(one, two);
		return (1);
	}
	return (0);
}

void		ft_links_rooms(t_room **rooms, char **args, int len)
{
	t_room	*tmp_room_one;
	t_room	*tmp_room_two;
	int		cursors[4];
	char	**tmp_link;

	cursors[0] = 0;
	cursors[2] = 0;
	cursors[3] = 0;
	while (args[cursors[0]] && (ft_strchr(args[cursors[0]], '#') ||
				ft_strchr(args[cursors[0]], '-')))
	{
		if (!ft_strchr(args[cursors[0]], '#'))
		{
			tmp_link = init(cursors, &tmp_room_one, &tmp_room_two, args);
			get_rooms(rooms, &tmp_room_one, &tmp_room_two, tmp_link);
			if (!final_cond(tmp_room_one, tmp_room_two, cursors, tmp_link))
				return ;
		}
		cursors[0]++;
	}
	if (cursors[3] && !cursors[2])
		ft_block("None of yours links corresponded to any room you gave, think you messed up with your ant-hills");
	if (!cursors[2])
		ft_block("No links, ants can't fly!\n");
}
