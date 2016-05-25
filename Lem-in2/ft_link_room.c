/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:45:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 15:37:11 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	reinit(t_room *room, t_room ***tmp_link, int *i, int *tmp)
{
	*tmp_link = room->links;
	*i = 0;
	*tmp = -1;
}

void		ft_link_room(t_room *room_one, t_room *room_two)
{
	t_room	**tmp_link;
	int		i;
	int		tmp;

	reinit(room_one, &tmp_link, &i, &tmp);
	while (tmp_link && tmp_link[i]->name)
		i++;
	room_one->links = (t_room**)malloc(sizeof(t_room*) * (i + 2));
	while (++tmp < i)
		room_one->links[tmp] = tmp_link[tmp];
	room_one->links[i] = room_two;
	room_one->links[i + 1] = ft_create_room(NULL, 0, 0);
	free(tmp_link ? tmp_link[i] : NULL);
	free(tmp_link);
	reinit(room_two, &tmp_link, &i, &tmp);
	while (tmp_link && tmp_link[i]->name)
		i++;
	room_two->links = (t_room**)malloc(sizeof(t_room*) * (i + 2));
	while (++tmp < i)
		room_two->links[tmp] = tmp_link[tmp];
	room_two->links[i] = room_one;
	room_two->links[i + 1] = ft_create_room(NULL, 0, 0);
	free(tmp_link ? tmp_link[i] : NULL);
	free(tmp_link);
}
