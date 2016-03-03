/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 17:27:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_sol   *ft_try_ab(t_stack *alpha, t_stack *beta)
{
    t_sol *solutions;
    
    solutions = ft_new_sol();
    while (ft_is_sorted(alpha) == 0 && ft_is_sorted(beta) == 0)
    {
        if (alpha->element > alpha->next->element)
            ft_add_sol(solutions, ft_sa(alpha));
        if (beta->element < beta->next->element)
            ft_add_sol(solutions, ft_sa(beta));
        if (ft_direction(alpha) && ft_direction(beta))
            ft_add_sol(solutions, ft_rr(alpha, beta));
        if (ft_direction(alpha) && !ft_direction(beta))
        {
            ft_add_sol(solutions, ft_ra(alpha));
            ft_add_sol(solutions, ft_rra(beta));
        }
        if (!ft_direction(alpha) && ft_direction(beta))
        {
            ft_add_sol(solutions, ft_rra(alpha));
            ft_add_sol(solutions, ft_ra(beta));
        }
        if (!ft_direction(alpha) && !ft_direction(beta))
            ft_add_sol(solutions, ft_rrr(alpha, beta));
    }
    ft_add_num_sol(solutions, ft_restack(alpha, beta));
    return (solutions);
}

t_sol   *ft_atob(t_stack *alpha, t_stack *beta, int trans_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;
    solutions = ft_new_sol();
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(alpha, beta));
    ft_add_num_sol(solutions, ft_try_ab(alpha, beta));
    ft_add_num_sol(solutions, ft_restack(alpha, beta));
    return (solutions);
}

t_sol   *ft_btoa(t_stack *alpha, t_stack *beta, int trans_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;
    solutions = ft_new_sol();
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(beta, alpha));
    ft_add_num_sol(solutions, ft_try_ab(alpha, beta));
    ft_add_num_sol(solutions, ft_restack(alpha, beta));
    return (solutions);
}

t_sol   *ft_new_sol(void)
{
    t_sol *sol;
    
    sol = (t_sol*)malloc(sizeof(t_sol));
    sol->operations = ft_strnew(3);
    sol->next = NULL;
	return (sol);
}

void    ft_add_sol(t_sol *solutions, char *sol)
{
    t_sol   *new;
    t_sol   *tmp;
    
    tmp = solutions;
	if (solutions == NULL)
	{
		solutions = ft_new_sol();
		solutions->operations = ft_strcpy(solutions->operations, sol);
	}
	else
	{
   		while (tmp->next != NULL)
        	tmp = tmp->next;
    	new = ft_new_sol();
    	new->operations = ft_strcpy(new->operations, sol);
    	tmp->next = new;
	}
}

void    ft_add_num_sol(t_sol *solutions, t_sol *to_add)
{
    t_sol   *tmp;
    
    tmp = solutions;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = to_add;
}
