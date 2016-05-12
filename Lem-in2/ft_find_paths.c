/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 16:21:34 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	**ft_find_paths(t_room **rooms)
{
	t_path	**result;
	t_room	*start;
	int		i;

	i = 0;
	while (rooms[i]->name)
	{
		if (rooms[i]->is_start)
		{
			start = rooms[i];
			break;
		}
		i++;
	}
	i = 0;
	while (start->links[i] && start->links[i]->name)
		i++;
	result = (t_path**)malloc(sizeof(t_path*) * i + 1);
	while (i >= 0)
	{
		result[i] = NULL;
		i--;
	}
	result[0] = ft_build_path(start, result[0], result);
	i = 0;
	while (result[i] != NULL)
	{
		i++;
		result[i] = ft_build_path(start, result[i], result);
	}
	printf("On vient de construire tous les chemins possibles\n");
	return (result);
}
