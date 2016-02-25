/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 08:54:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 13:46:09 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_direction(t_stack *alpha)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = ft_rev_stack(alpha);
	if (ft_middle_coeff(alpha) == 1 && !ft_strcmp(alpha->name, "a"))
		return (0);
	else if (ft_middle_coeff(alpha) == 2 && !ft_strcmp(alpha->name, "a"))
		return (1);
	else if (ft_middle_coeff(tmp) == 1 && !ft_strcmp(alpha->name, "b"))
		return (0);
	else if (ft_middle_coeff(tmp) == 2 && !ft_strcmp(alpha->name, "b"))
		return (1);
	else
		while (i < alpha->len - 1 && ((tmp->stack[i] <= tmp->stack[i + 1] &&
						!ft_strcmp(alpha->name, "b")) ||
					(alpha->stack[i] <= alpha->stack[i + 1] &&
					 !ft_strcmp(alpha->name, "a"))))
			i++;
	if (i > alpha->len / 2)
		return (0);
	else
		return (1);
}
