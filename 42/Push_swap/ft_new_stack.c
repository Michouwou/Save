/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:37:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 10:12:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_zero(char *str)
{
	int	i;

	i = str[0] == '-' || str[0] == '+' ? 1 : 0;
	while (str[i] && str[i] == '0')
		i++;
	if (i < (int)ft_strlen(str))
		return (0);
	return (1);
}

static void	if_non_zero(int code, char *str, t_stack *new)
{
	if ((ft_isdigit(str[0]) || (str[1] && ft_isdigit(str[1]))) &&
			!new->number)
	{
		if (!code)
			ft_error(3, str);
		ft_error_loop(3, str);
	}
}

t_stack		*ft_new_stack(char *str, int index, int code)
{
	t_stack	*new;
	int		i;

	i = 0;
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (!code)
				ft_error(1, str);
			ft_error_loop(1, str);
			return ((void*)-1);
		}
		i++;
	}
	new = (t_stack*)malloc(sizeof(t_stack));
	new->number = ft_atoi(str);
	if (!is_zero(str))
		if_non_zero(code, str, new);
	new->index = index;
	new->str_rep = ft_strdup(str);
	new->next = NULL;
	return (new);
}
