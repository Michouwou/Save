/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:35:31 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 10:25:34 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(char **args, int code)
{
	int		i;
	t_stack	*tmp;
	t_stack	*first;

	i = 0;
	first = NULL;
	while (args[i])
	{
		if ((args[i][0] == '+' || args[i][0] == '-' ||
					ft_isdigit(args[i][0])) && !(args[i][1] &&
					!ft_isdigit(args[i][1])))
		{
			tmp = ft_new_stack(args[i], i, code);
			if (tmp == (void*)-1)
				return ((void*)-1);
			ft_push_back(&first, tmp);
		}
		else
		{
			if (code == 0)
				ft_error(1, args[i]);
			ft_error_loop(1, args[i]);
			return ((void*)-1);
		}
		if (code == 1)
			free(args[i]);
		i++;
	}
	return (first);
}
