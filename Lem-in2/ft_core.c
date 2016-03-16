/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:07 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 14:57:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_core(t_room **rooms, t_ant **ants)
{
	t_path	**paths;
	int		status;

	printf("---Entree dans CORE, room[0]->name = %s\n", rooms[0]->name);
	fflush(stdout);
	paths = ft_find_paths(rooms);
	printf("---Find paths seems okay\n");
	fflush(stdout);
	status = 1;
	while (status)
		status = ft_iterate(ants, paths);
	printf("---About to free everything\n");
	fflush(stdout);
	ft_free_everything(paths, rooms, ants);
}
