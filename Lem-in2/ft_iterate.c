/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/21 10:37:51 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iterate(t_ant **ants, t_path **paths)
{
	int	i;
	int	j;

	i = 0;
	printf("path[0]->name : %s\n", paths[0]->room->name);
	fflush(stdout);
	while (ants[i] != NULL && ants[i]->path != NULL)
	{
		if (!ants[i]->actual)
			ants[i]->actual = ants[i]->path->room;
		else if (!ants[i]->actual->is_end)
		{
			if (i)
				ft_printf(" ");
			ants[i]->actual = ants[i]->path->next->room;
			ants[i]->path = ants[i]->path->next;
			ft_print_move(ants[i]);
		}
		i++;
	}
	ft_printf("\n");
	if (ants[i] == NULL && ants[i - 1]->actual->is_end)
		return (0);
	j = 0;
	while (ants[i] && paths[j] && paths[j]->coeff > 0)
	{
		ants[i]->path = paths[j];
		paths[j]->coeff--;
		j++;
		i++;
	}
	printf("i : %d, ants[0]->path exists? %s\n", i, ants[0]->path->room->name);
	return (1);
}
