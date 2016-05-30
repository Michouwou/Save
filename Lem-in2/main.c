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

static void	treatment(int fd, char **args, t_ant **ants, t_room **rooms)
{
	int		num_ants;
	int		num_rooms;

	num_ants = 0;
	num_rooms = 0;
	ft_printf("On entre dans treatment\n");
	ft_get_ants(&args, &num_ants, &ants);
	ft_printf("On a recup les fourmis\n");
	ft_get_rooms(&args, &num_rooms, &rooms);
	ft_printf("La les pieces\n");
	if (!num_rooms)
		ft_block("There is no room, where do you want the ants to go?\n");
	ft_links_rooms(rooms, args, num_rooms);
	ft_printf("Les pieces sont reliees\n");
	ft_core(rooms, ants, num_ants);
	ft_printf("On sort de core\n");
}

int			main(int ac, char **av)
{
	int		fd;
	char	**args;
	t_ant	**ants;
	t_room	**rooms;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		ft_block("Hum... you have to give me exactly one file name to read");
	args = ft_read_file(fd);
	ft_printf("On vient de recuperer les arguments\n");
	if (fd != -1 && args)
		treatment(fd, args, ants, rooms);
	else if (fd == -1)
		ft_block("There was a problem reading the file...");
	else if (!args)
		ft_block("LMAO, the file was empty!");
	ft_printf("On est plus dans treatment\n");
	fd = -1;
	while (args[++fd])
		free(args[fd]);
	ft_printf("On a free les args\n");
	free(args);
	close(fd);
	while (1);
	return (0);
}
