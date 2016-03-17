/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_is_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:33:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/17 13:17:48 by mlevieux         ###   ########.fr       */
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
	int j = 0;
	while (tmp)
	{
		printf("\tOn test : %s\n", tmp->room->name);
		i = 0;
		while (all_paths[i])
		{
			printf("\t\tOn entame un path :\n");
			cursor = all_paths[i];
			while (cursor)
			{
				printf("\t\t\tLe path est sur %s\n", cursor->room->name);
				if (!ft_strcmp(cursor->room->name, path->room->name) && !cursor->room->is_start && !cursor->room->is_end)
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
