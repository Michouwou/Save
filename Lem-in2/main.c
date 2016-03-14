/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 16:49:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	**args;
	t_ant	**ants;
	t_room	**rooms;
	int		num_ants;
	int		num_rooms;

	printf("ON Y EST\n");
	fflush(stdout);
	fd = open("test.txt", O_RDONLY);
	printf("Apres ouverture de test, fd = %d\n", fd);
	fflush(stdout);
	args = ft_read_file(fd);
	int i = 0;
	while (args[i])
	{
		write(1, args[i], ft_strlen(args[i]));
		write(1, "\n", 1);
		i++;
	}
	fflush(stdout);
	ants = ft_get_ants(&args, &num_ants);
	printf("Sortie de get ants\n");
	fflush(stdout);
	rooms = ft_get_rooms(&args, &num_rooms);
	printf("sortie de get rooms et entree dans CORE\n");
	fflush(stdout);
	ft_core(rooms, ants);
	printf("Eh?\n");
	fflush(stdout);
	return (0);
}
