/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_med.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:02:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 14:40:47 by mlevieux         ###   ########.fr       */
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

static int		ft_tab_is_sorted(int *tab, t_stack *alpha, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int		ft_sort_tab(int **tab, t_stack *alpha)
{
	int	i;
	int	len;

	i = 0;
	len = ft_stack_len(alpha);
	while (!ft_tab_is_sorted(*tab, alpha, len))
	{
		if (i == len - 1)
			i = 0;
		if ((*tab)[i] > (*tab)[i + 1])
		{
			(*tab)[i] = (*tab)[i] + (*tab)[i + 1];
			(*tab)[i + 1] = (*tab)[i] - (*tab)[i + 1];
			(*tab)[i] = (*tab)[i] - (*tab)[i + 1];
		}
		i++;
	}
	return (len);
}

int			ft_stack_med(t_stack *alpha)
{
	t_stack	*tmp;
	int		med;
	int		*tab;
	int		len;

	tab = ft_to_tab(alpha);
	len = ft_sort_tab(&tab, alpha);
	med = tab[len / 2];
	return (med);
}
