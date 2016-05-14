/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/14 16:48:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**args;
	t_ant	**ants;
	t_room	**rooms;
	int		num_ants;
	int		num_rooms;

	num_rooms = 0;
	num_ants = 0;
	fd = open(av[1], O_RDONLY);
	args = ft_read_file(fd);
	if (fd != -1)
	{
		ft_get_ants(&args, &num_ants, &ants);
		ft_get_rooms(&args, &num_rooms, &rooms);
		if (!num_rooms)
			ft_block("There is no room, where do you want the ants to go dude?\n");
		ft_links_rooms(rooms, args, num_rooms);
		ft_core(rooms, ants, num_ants);
	}
	return (0);
}
