/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_med.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:02:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 11:49:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*ft_to_tab(t_stack *alpha)
{
	int 	i;
	int		*ret;
	t_stack	*tmp;

	tmp = alpha;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	ret = (int*)malloc(sizeof(int) * i);
	i = 0;
	tmp = alpha;
	while (tmp != NULL)
	{
		ret[i] = tmp->element;
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

static int		ft_tab_len(int *tab)
{
	return (sizeof(tab) / 4);
}

static int		ft_tab_is_sorted(int *tab)
{
	int i;

	i = 0;
	while (i < ft_tab_len(tab) - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void		ft_sort_tab(int **tab)
{
	int	i;

	i = 0;
	while (!ft_tab_is_sorted(*tab))
	{
		if (i == ft_tab_len(*tab) - 1)
			i = 0;
		if ((*tab)[i] > (*tab)[i + 1])
		{
			(*tab)[i] = (*tab)[i] + (*tab)[i + 1];
			(*tab)[i + 1] = (*tab)[i] - (*tab)[i + 1];
			(*tab)[i] = (*tab)[i] - (*tab)[i + 1];
		}
		i++;
	}
}

int			ft_stack_med(t_stack *alpha)
{
	t_stack	*tmp;
	int		med;
	int		*tab;

	tab = ft_to_tab(alpha);
	ft_sort_tab(&tab);
	med = tab[ft_tab_len(tab) / 2 + 1];
	return (med);
}
