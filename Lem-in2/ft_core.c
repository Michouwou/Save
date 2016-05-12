/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:07 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 16:31:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_core(t_room **rooms, t_ant **ants, int num_ants)
{
	t_path	**paths;
	int		status;

	printf("On est dans core et on attaque le traitement\n");
	paths = ft_find_paths(rooms);
	printf("On vient de trouver tous les chemins\n");
	ft_paths_coeff(paths, num_ants);
	printf("On a associe a chaque chemin un coefficient\n");
	status = 1;
	while (status)
		status = ft_iterate(ants, paths);
	printf("Les iterations sont finies, on libere la memoire\n");
	ft_free_everything(paths, rooms, ants);
}
