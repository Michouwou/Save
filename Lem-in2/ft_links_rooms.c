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

void	ft_links_rooms(t_room **rooms, char **args, int len)
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
			cursors[3] = 1;
			cursors[1] = 0;
			tmp_room_one = NULL;
			tmp_room_two = NULL;
			tmp_link = ft_strsplit(args[cursors[0]], '-');
			while (rooms[cursors[1]]->name && !(tmp_room_one && tmp_room_two))
			{
				if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[0]))
					tmp_room_one = rooms[cursors[1]];
				if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[1]))
					tmp_room_two = rooms[cursors[1]];
				cursors[1]++;
			}
			if (tmp_room_one && tmp_room_two)
			{
				cursors[2] = 1;
				ft_link_room(tmp_room_one, tmp_room_two);
			}
			else
				return ;
			free(tmp_link[0]);
			free(tmp_link[1]);
		}
		cursors[0]++;
	}
	if (cursors[3] && !cursors[2])
		ft_block("None of yours links corresponded to any room you gave, think you messed up with your ant-hills");
	if (!cursors[2])
		ft_block("No links, ants can't fly!\n");
}
