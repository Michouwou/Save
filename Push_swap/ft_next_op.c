/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:40:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 12:07:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_next_op(t_stack *alpha, char *options)
{
	if (ft_middle_coeff(alpha) == 1)
		return ("rr");
	else if (alpha->stack[0] > alpha->stack[1])
		return ("sw");
	else if (ft_direction(alpha) == 1)
	   return ("ro");	
}
