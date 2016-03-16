/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:45:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 14:53:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_link_room(t_room *room_one, t_room *room_two)
{
	t_room	**tmp_link_one;
	t_room	**tmp_link_two;
	int		i;
	int		j;
	int		tmp;

	printf("on et dans link_room\n");
	fflush(stdout);
	tmp_link_one = room_one->links;
	tmp_link_two = room_two->links;
	i = 0;
	j = 0;
	tmp = -1;
	while (tmp_link_one && tmp_link_one[i]->name)
		i++;
	while (tmp_link_two && tmp_link_two[j]->name)
		j++;
	printf("Jusque la tout va bien\n");
	fflush(stdout);
	room_one->links = (t_room**)malloc(sizeof(t_room*) * (i + 2));
	room_two->links = (t_room**)malloc(sizeof(t_room*) * (j + 2));
	while (++tmp < i)
		room_one->links[tmp] = tmp_link_one[tmp];
	printf("Apres la premiere boucle\n");
	fflush(stdout);
	room_one->links[i] = room_two;
	room_one->links[i + 1] = ft_create_room(NULL, 0, 0);
	tmp = -1;
	while (++tmp < j)
		room_two->links[tmp] = tmp_link_two[tmp];
	printf("apres la deuxieme boucle\n");
	fflush(stdout);
	room_two->links[j] = room_one;
	room_two->links[j + 1] = ft_create_room(NULL, 0, 0);
	free(tmp_link_one);
	free(tmp_link_two);
	printf("fin de la fonction\n");
	fflush(stdout);
}
