/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 10:34:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_middle_swap(t_stack **alpha, int position, t_sol **solution)
{
    int i;
    
    i = 0;
    while (i < position || i < -position)
    {
        ft_add_sol(solution, (position < 0) ? ft_rra(alpha) : ft_ra(alpha));
        i++;
    }
    ft_add_sol(solution, ft_sa(alpha));
}