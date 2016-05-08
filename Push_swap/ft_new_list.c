/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:44:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 13:08:39 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int num, int index)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->number = num;
	new->index = index;
	return (new);
}

void	ft_push_back(t_stack **stack, t_stack *to_add)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = to_add;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
}

int		ft_get_options(char *options, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i][0] == '-' && !ft_isdigit(args[i][1]))
	{
		j = 1;
		while (args[i][j])
		{
			if (args[i][j] == 'c')
				options[0] = 1;
			else if (args[i][j] == 'C')
				options[1] = 1;
			else if (args[i][j] == 'd')
				options[2] = 1;
			else if (args[i][j] == 'v')
				options[3] = 1;
			else if (args[i][j] == 't')
				options[4] = 1;
			else
				ft_error(0);
			j++;
		}
		i++;
	}
	return (i);
}

t_stack	*ft_create_stack(char **args)
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
			tmp = ft_new_stack(ft_atoi(args[i]), i);
			ft_push_back(&first, tmp);
		}
		else
			ft_error(1);
		i++;
	}
	return (first);
}

int		ft_get_min(t_stack *stack)
{
	t_stack			*tmp;
	int				ret;
	long int		tmpi;

	tmp = stack;
	tmpi = LONG_MAX;
	while (tmp)
	{
		if (tmp->number < tmpi)
		{
			tmpi = tmp->number;
			ret = tmp->index;
		}
		tmp = tmp->next;
	}
	return (ret);
}

int		ft_direction(t_stack *stack, int index)
{
	int		i;
	t_stack	*tmp;

	while (tmp->index != index)
	{
		++i;
		tmp = tmp->next;
	}
	while (tmp)
	{
		--i;
		tmp = tmp->next;
	}
	if (i < 0)
		return (1);
	else
		return (2);
}

void	ft_move(t_stack **stack, int direction, int index, char **sols)
{
	int	i;

	i = 0;
	if (direction == 1)
		while ((*stack)->index != index)
		{
			ft_r(stack);
			*sols = ft_strjoin_free(*sols, " ra");
		}
	else
		while ((*stack)->index != index)
		{
			ft_rr(stack);
			*sols = ft_strjoin_free(*sols, " rra");
		}
}

void	ft_repush(t_stack **stack_two, t_stack **stack_one, char **sols)
{
	int	i;

	i = 0;
	while (*stack_two)
	{
		ft_p(stack_two, stack_one);
		*sols = ft_strjoin_free(*sols, " pa");
	}
}
