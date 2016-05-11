/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:44:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 11:15:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stack ***stacks, int direction, int index, char **sols)
{
	int	i;

	i = 0;
	if (direction % 10 == 1)
		while (((*stacks)[0])->index != index)
		{
			ft_r(&((*stacks)[0]));
			*sols = ft_strjoin_free(*sols, " ra");
			if (direction > 10)
			{
				write(1, "\nAction : ra", 12);
				ft_print_stack((*stacks)[0], (*stacks)[1], "ra");
			}
		}
	else
		while (((*stacks)[0])->index != index)
		{
			ft_rr(&((*stacks)[0]));
			*sols = ft_strjoin_free(*sols, " rra");
			if (direction > 10)
			{
				write(1, "\nAction : rra", 13);
				ft_print_stack((*stacks)[0], (*stacks)[1], "rra");
			}
		}
}
