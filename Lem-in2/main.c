/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 14:06:17 by mlevieux         ###   ########.fr       */
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

	printf("ON Y EST\n");
	fflush(stdout);
	fd = open("test.txt", O_RDONLY);
	printf("Apres ouverture de tes, fd = %d\n", fd);
	fflush(stdout);
	args = ft_read_file(fd);
	printf("Lecture du fichier termine, les premieres lignes de args : %s\n %s\n %s\n", args[0], args[1], args[2]);
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
