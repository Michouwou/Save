/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:28:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 10:23:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_links_rooms(t_room **rooms, char **args, int len)
{
	t_room	*tmp_room_one;
	t_room	*tmp_room_two;
	int		cursors[2];
	char	**tmp_link;

	printf("Entree dans links_rooms\n");
	fflush(stdout);
	cursors[0] = 0;
	while (cursors[0] < len)
	{
		cursors[1] = 0;
		tmp_room_one = NULL;
		tmp_room_two = NULL;
		tmp_link = ft_strsplit(args[cursors[0]], '-');
		printf("Inside the first loop, about to enter the second, name %s\n", rooms[0]->name);
		fflush(stdout);
		while (rooms[cursors[1]]->name && !(tmp_room_one && tmp_room_two))
		{
			printf("Inside the second loop\n");
			fflush(stdout);
			if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[0]))
				tmp_room_one = rooms[cursors[1]];
			if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[1]))
				tmp_room_two = rooms[cursors[1]];
			cursors[1]++;
		}
		printf("Just got out of the second loop\n");
		fflush(stdout);
		ft_link_room(tmp_room_one, tmp_room_two);
		printf("Problem in link?\n");
		fflush(stdout);
		free(tmp_link[0]);
		free(tmp_link[1]);
		cursors[0]++;
	}
	printf("on sort de links\n");
	fflush(stdout);
}
