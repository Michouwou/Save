/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:40:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 14:02:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_next_op(t_stack *alpha)
{
	if (ft_middle_coeff(alpha) == 1)
		return ("rr");
	else if (alpha->stack[0] > alpha->stack[1])
		return ("sw");
	else if (ft_direction(alpha) == 1)
	   return ("ro");
	else
		return ("rr");
}

char	*ft_double_op(t_stack *alpha, t_stack *beta, char is_ext)
{
	if (!ft_strcmp(ft_next_op(alpha), "rr"))
		return (ft_drrotate(alpha, beta, is_ext));
	else if (!ft_strcmp(ft_next_op(alpha), "sw"))
		return (ft_dswap(alpha, beta, is_ext));
	else
	   return (ft_drotate(alpha, beta, is_ext));	
}

char	*ft_dnext_op(t_stack *alpha, t_stack *beta, char is_ext)
{
	char tmp1[2];
	char tmp2[2];

	tmp1 = ft_strcpy(tmp1, ft_next_op(alpha));
	tmp2 = ft_strcpy(tmp2, ft_next_op(ft_rev_stack(beta)));
	if (!ft_strcmp(tmp1, tmp2))
		return (ft_double_op(alpha, beta, is_ext));
	if (beta->len < alpha->len - 1 && beta->len + alpha->len > 3)
		return (ft_push(alpha, beta, is_ext));
	else if (!ft_strcmp(tmp1, "sw"))
		return (ft_swap_e(alpha, is_ext));
	else if (!ft_strcmp(tmp2, "sw"))
		return (ft_swap_e(beta, is_ext));
	else if (!ft_strcmp(tmp1, "rr"))
		return (ft_rrotate(alpha, is_ext));
	else if (!ft_strcmp(tmp2, "rr"))
		return (ft_rrotate(beta, is_ext));
	else if (!ft_strcmp(tmp1, "ro"))
		return (ft_rotate(alpha, is_ext));
	else (!ft_strcmp(tmp2, "ro"))
		return (ft_rotate(beta, is_ext));
}

t_stack	*ft_rev_stack(t_stack *stack)
{
	int		i;
	t_stack	new;

	i = 0;
	new = ft_create_stack();
	while (i < stack->len)
		new->stack[i] = stack->stack[i] * (-1);
	new->len = stack->len;
	return (new);
}
