/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 09:47:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	int		fd;
	char	**args;
	t_ant	**ants;
	t_room	**rooms;
	int		num_ants;
	int		num_rooms;

	num_rooms = 0;
	num_ants = 0;
	printf("ON Y EST\n");
	fflush(stdout);
	fd = open("test.txt", O_RDONLY);
	printf("Apres ouverture de test, fd = %d\n", fd);
	fflush(stdout);
	args = ft_read_file(fd);
	ft_get_ants(&args, &num_ants, &ants);
	printf("Sortie de get ants\n");
	fflush(stdout);
	ft_get_rooms(&args, &num_rooms, &rooms);
	printf("sortie de get rooms et entree dans CORE %s\n", rooms[0]->name);
	fflush(stdout);
	ft_core(rooms, ants);
	printf("Eh?\n");
	fflush(stdout);
	return (0);
}
