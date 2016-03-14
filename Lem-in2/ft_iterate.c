/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 13:31:12 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iterate(t_ant **ants, t_path **paths)
{
	int	i;
	int	j;

	i = 0;
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
	ft_printf("\n");
	if (ants[i] == NULL)
		return (0);
	j = 0;
	while (ants[i] && paths[j])
	{
		ants[i]->path = paths[j];
		j++;
		i++;
	}
	if (ants[i] == NULL)
		return (0);
	return (1);
}
