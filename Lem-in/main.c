/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/04 12:05:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	treatment(t_ant **ants, t_room **rooms)
{
	int		num_ants;
	int		num_rooms;

	num_ants = 0;
	num_rooms = 0;
	ft_read(&rooms, &ants, &num_rooms, &num_ants);
	if (!num_rooms)
		ft_block("There is no room, where do you want the ants to go?\n");
	write(1, "\n", 1);
	ft_core(rooms, ants, num_ants);
}

int			main(void)
{
	t_ant	**ants;
	t_room	**rooms;

	ants = NULL;
	rooms = NULL;
	treatment(ants, rooms);
	while (1);
	return (0);
}
