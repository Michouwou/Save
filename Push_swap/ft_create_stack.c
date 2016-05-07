/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:22:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 15:34:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(char **args)
{
	int		i;
	t_stack	*tmp;
	t_stack	*first;

	i = 0;
	tmp = ft_new_list();
	first = tmp;
	while (args[i] != NULL)
	{
		if ((args[i][0] == '+' || args[i][0] == '-' ||
					ft_isdigit(args[i][0])) && (ft_isdigit(args[i][1]) ||
					!args[i][1]))
		{
			tmp->index = i;
			tmp->number = ft_atoi(args[i]);
		}
		else
			ft_error(0);
		tmp->next = ft_new_list();
		tmp = tmp->next;
	}
	return (first);
}
