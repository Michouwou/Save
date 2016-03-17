/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_is_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:33:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/17 11:02:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_path_is_free(t_path *path, t_path **all_paths)
{
	int		i;
	t_path	*tmp;
	t_path	*cursor;

	printf("Entree dans path_is_free\n");
	fflush(stdout);
	tmp = path;
/*	if (!path || !all_paths || !all_paths[0])
	{
		printf("LOL\n");
		fflush(stdout);
		return (1);
	}*/
	int j = 0;
	while (tmp)
	{
		i = 0;
		printf("boucle externe tmp->room : %s\n", tmp->room->name);
		fflush(stdout);
		while (all_paths[i])
		{
			cursor = all_paths[i];
			while (cursor)
			{
				if (!ft_strcmp(cursor->room->name, path->room->name))
					return (0);
				cursor = cursor->next;
			}
			i++;
		}
		j++;
		tmp = tmp->next;
	}
	printf("Sortie is_free\n");
	fflush(stdout);
	return (1);
}
