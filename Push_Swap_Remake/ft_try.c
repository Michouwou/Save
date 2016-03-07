/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 16:54:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * Ici respectivement des fonctions qui vont creer un nouvel espace solution,
 * ajouter une solution a un espace de solution, ajouter un espace de solution
 * a un autre espace solution
 **/

t_sol   *ft_new_sol(void)
{
    t_sol *sol;

	sol = (t_sol*)malloc(sizeof(t_sol));
    sol->operations = ft_strnew(3);
    sol->next = NULL;

	return (sol);
}

void    ft_add_sol(t_sol **solutions, char *sol)
{
    t_sol   *new;
    t_sol   *tmp;
    
	tmp = *solutions;
	if (!(*solutions))
	{
		*solutions = ft_new_sol();
		(*solutions)->operations = ft_strcpy((*solutions)->operations, sol);
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

void    ft_add_num_sol(t_sol **solutions, t_sol *to_add)
{
    t_sol   *tmp;
    
    tmp = *solutions;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = to_add;
	
	ft_display(*solutions, NULL);
}
