/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 15:55:11 by mlevieux         ###   ########.fr       */
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
	printf("%%%%%%Sortie de la boucle\n");
	fflush(stdout);
	result = (t_path**)malloc(sizeof(t_path*) * i);
	result[0] = NULL;
	result[0] = ft_build_path(start, result[0], result);
	i = 1;
	printf("%%%%%%about to enter the second loop\n");
	fflush(stdout);
	while (result[0])
	{
		printf("Attention : %s\n", result[0]->room->name);
		result[0] = result[0]->next;
	}
	exit(0);
	while ((result[i] = ft_build_path(start, result[i], result)) != NULL)
		i++;
	return (result);
}
