/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/26 10:46:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	treatment(t_ant **ants, t_room **rooms)
{
	int		num_ants;
	int		num_rooms;

	num_ants = 0;
	num_rooms = 0;
	ft_read_file(&rooms, &ants, &num_rooms, &num_ants);
	if (!num_rooms)
		ft_block("There is no room, where do you want the ants to go?\n");
	ft_core(rooms, ants, num_ants);
}

int			main(int ac, char **av)
{
	int		fd;
	char	**args;
	t_ant	**ants;
	t_room	**rooms;

	treatment(ants, rooms);
	return (0);
}
