/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:44:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 15:57:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_to_rrr(t_sol **tmp)
{
	t_sol *tmptmp;

	tmptmp = (*tmp)->next;
	(*tmp)->operations = ft_strcpy((*tmp)->operations, "rrr");
	if ((*tmp)->next->next)
		(*tmp)->next = (*tmp)->next->next;
	else
		(*tmp)->next = NULL;
	free(tmptmp);
}

static void ft_to_rr(t_sol **tmp)
{
	t_sol *tmptmp;

	tmptmp = (*tmp)->next;
	(*tmp)->operations = ft_strcpy((*tmp)->operations, "rr");
	if ((*tmp)->next->next)
		(*tmp)->next = (*tmp)->next->next;
	else
		(*tmp)->next = NULL;
	free(tmptmp);
}

static void ft_to_ss(t_sol **tmp)
{
	t_sol *tmptmp;

	tmptmp = (*tmp)->next;
	(*tmp)->operations = ft_strcpy((*tmp)->operations, "ss");
	if ((*tmp)->next->next)
		(*tmp)->next = (*tmp)->next->next;
	else
		(*tmp)->next = NULL;
	free(tmptmp);
}

void	ft_ator(t_sol **solution)
{
	t_sol *tmp;

	tmp = *solution;
	while (tmp && tmp->next)
	{
		if ((!ft_strcmp(tmp->operations, "rra") &&
					!ft_strcmp(tmp->next->operations, "rrb")) ||
				(!ft_strcmp(tmp->operations, "rrb") &&
				 !ft_strcmp(tmp->next->operations, "rra")))
			ft_to_rrr(&tmp);
		if ((!ft_strcmp(tmp->operations, "ra") &&
					!ft_strcmp(tmp->next->operations, "rb")) ||
				(!ft_strcmp(tmp->operations, "rb") &&
				 !ft_strcmp(tmp->next->operations, "ra")))
			ft_to_rr(&tmp);
		if ((!ft_strcmp(tmp->operations, "sa") &&
					!ft_strcmp(tmp->next->operations, "sb")) ||
				(!ft_strcmp(tmp->operations, "sb") &&
				 !ft_strcmp(tmp->next->operations, "sa")))
			ft_to_ss(&tmp);
		tmp = tmp->next;
	}
}
