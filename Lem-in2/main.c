/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:12:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 16:31:41 by mlevieux         ###   ########.fr       */
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
	fd = open("test.txt", O_RDONLY);
	printf("On a ouvert le fichier, fd = %d\n", fd);
	args = ft_read_file(fd);
	printf("On vient de lire la totalite du fichier\n");fflush(stdout);
	ft_get_ants(&args, &num_ants, &ants);
	printf("On est de retour dans main apres avoir cree les fourmis\n");
	ft_get_rooms(&args, &num_rooms, &rooms);
	printf("On vient de recuperer les salle donnees en argument\n");
	ft_links_rooms(rooms, args, num_rooms);
	ft_core(rooms, ants, num_ants);
	printf("Le programme est termine, on quitte\n");
	return (0);
}
