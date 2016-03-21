/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:07 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/21 10:15:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_core(t_room **rooms, t_ant **ants, int num_ants)
{
	t_path	**paths;
	int		status;

	printf("---Entree dans CORE, room[0]->name = %s\n", rooms[0]->name);
	fflush(stdout);
	paths = ft_find_paths(rooms);
	ft_paths_coeff(paths, num_ants);
	printf("---Find paths seems okay paths[0] = %s\n", paths[0]->room->name);
	fflush(stdout);
	status = 1;
	while (status)
		status = ft_iterate(ants, paths);
	printf("---About to free everything\n");
	fflush(stdout);
	ft_free_everything(paths, rooms, ants);
}
