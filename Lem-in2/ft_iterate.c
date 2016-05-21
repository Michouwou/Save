/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:24:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/15 13:36:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	loop(t_ant **ants, t_path **paths, int *i, int *j)
{
	if (!ants[*i]->actual && ants[*i]->path)
		ants[*i]->actual = ants[*i]->path->room;
	else if (ants[*i]->actual && !ants[*i]->actual->is_end)
	{
		if (j)
			ft_printf(" ");
		ants[*i]->actual = ants[*i]->path->next->room;
		ants[*i]->path = ants[*i]->path->next;
		ft_print_move(ants[*i]);
		(*j)++;
	}
	(*i)++;
}

int			ft_iterate(t_ant **ants, t_path **paths)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ants[i] != NULL && ants[i]->path != NULL)
		loop(ants, paths, &i, &j);
	if (j)
		ft_printf("\n");
	if ((ants[i] == NULL && ants[i - 1]->actual->is_end) || paths[0] == NULL)
		return (0);
	j = 0;
	while (ants[i] && paths[j] && paths[j]->coeff >= 0)
	{
		ants[i]->path = paths[j];
		paths[j]->coeff--;
		j++;
		i++;
	}
	return (1);
}
