/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/17 11:34:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iterate(t_ant **ants, t_path **paths)
{
	int	i;
	int	j;

	i = 0;
	printf("ants[0]->number : %d, ants[0]->actual exists? %s\n", ants[0]->number, ants[0]->actual ? "yes" : "no");
	fflush(stdout);
	while (ants[i] != NULL && ants[i]->path != NULL)
	{
		if (!ants[i]->actual->is_end)
		{
			if (i)
				ft_printf(" ");
			ants[i]->actual = ants[i]->path->next->room;
			ants[i]->path = ants[i]->path->next;
			ft_print_move(ants[i]);
		}
		i++;
	}
	ft_printf("blop\n");
	if (ants[i] == NULL)
		return (0);
	j = 0;
	while (ants[i] && paths[j])
	{
		ants[i]->path = paths[j];
		j++;
		i++;
	}
	printf("ants[0]->number : %d, ants[0]->actual exists? %s\n", ants[0]->number, ants[0]->actual ? "yes" : "no");
	exit(0);
	if (ants[i] == NULL)
		return (0);
	return (1);
}
