/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/17 11:30:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	**ft_find_paths(t_room **rooms)
{
	t_path	**result;
	t_room	*start;
	int		i;

	printf("%%%%%%Entree dans find_paths\n");
	fflush(stdout);
	i = 0;
	while (rooms[i]->name)
	{
		printf("PASSE!!\n");
		fflush(stdout);
		if (rooms[i]->is_start)
		{
			start = rooms[i];
			break;
		}
		i++;
	}
	printf("%%%%%%Sortie de la boucle, start is in room %s\n", start->name);
	fflush(stdout);
	i = 0;
	while (start->links[i] && start->links[i]->name)
		i++;
	result = (t_path**)malloc(sizeof(t_path*) * i);
	while (i > 0)
	{
		result[i - 1] = NULL;
		i--;
	}
	result[0] = ft_build_path(start, result[0], result);
	i = 0;
	printf("%%%%%%about to enter the second loop\n");
	fflush(stdout);
	while (result[i]!= NULL)
	{
		i++;
		result[i] = ft_build_path(start, result[i], result);
	}
	return (result);
}
