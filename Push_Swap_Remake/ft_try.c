/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:59:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * Ci dessous les trois fonctions aui testent les differents chemains de tri des piles
 **/

t_sol   *ft_try_ab(t_stack *alpha, t_stack *beta)
{
    t_sol *solutions;
   
  	printf("Entree dans ft_try_ab\n");
	fflush(stdout);

    solutions = ft_new_sol();
	int i = 0;
	
	printf("Entre dans la boucle de try_ab\n");
	fflush(stdout);

    while (ft_is_sorted(alpha) == 0 || ft_is_sorted(beta) == 0)
    {
		if (i++ >= 5)
			exit(0);
        if (alpha->element > alpha->next->element)
            ft_add_sol(solutions, ft_sa(alpha));
        if (beta->element < beta->next->element)
            ft_add_sol(solutions, ft_sa(beta));
        if (ft_direction(alpha) && ft_direction(beta))
            ft_add_sol(solutions, ft_rr(alpha, beta));
        if (ft_direction(alpha) && !ft_direction(beta))
        {
            ft_add_sol(solutions, ft_ra(alpha));
            ft_add_sol(solutions, ft_rra(&beta));
        }
        if (!ft_direction(alpha) && ft_direction(beta))
        {
            ft_add_sol(solutions, ft_rra(&alpha));
            ft_add_sol(solutions, ft_ra(beta));
        }
        if (!ft_direction(alpha) && !ft_direction(beta))
            ft_add_sol(solutions, ft_rrr(alpha, beta));
    }

	printf("Ajout de la liste d'operations aux operations effectuees\n");
	fflush(stdout);

    ft_add_num_sol(solutions, ft_restack(alpha, beta));
    
	printf("Sortie de try_ab\n");
	fflush(stdout);
	
	return (solutions);
}

t_sol   *ft_atob(t_stack *alpha, t_stack *beta, int trans_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;

	printf("Entree dans atob\n");
	fflush(stdout);

    solutions = ft_new_sol();
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(alpha, beta));

	printf("Tranfert OK\n");
	fflush(stdout);

    ft_add_num_sol(solutions, ft_try_ab(alpha, beta));
    ft_add_num_sol(solutions, ft_restack(alpha, beta));

	printf("Sortie de la fonction\n");
	fflush(stdout);

    return (solutions);
}

t_sol   *ft_btoa(t_stack *alpha, t_stack *beta, int trans_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;
    
	printf("Entree dans btoa\n");
	fflush(stdout);

	solutions = ft_new_sol();
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(beta, alpha));
    
	printf("Transfert termine\n");
	fflush(stdout);

	ft_add_num_sol(solutions, ft_try_ab(alpha, beta));
    ft_add_num_sol(solutions, ft_restack(alpha, beta));

	printf("Sortie de btoa\n");
	fflush(stdout);

    return (solutions);
}

/**
 * Ici respectivement des fonctions qui vont creer un nouvel espace solution,
 * ajouter une solution a un espace de solution, ajouter un espace de solution
 * a un autre espace solution
 **/

t_sol   *ft_new_sol(void)
{
    t_sol *sol;
    
    printf("Entree dans new_sol\n");
	fflush(stdout);

	sol = (t_sol*)malloc(sizeof(t_sol));
    sol->operations = ft_strnew(3);
    sol->next = NULL;

	printf("Sortie de new_sol\n");
	fflush(stdout);

	return (sol);
}

void    ft_add_sol(t_sol *solutions, char *sol)
{
    t_sol   *new;
    t_sol   *tmp;
    
    printf("Entree dans add_sol\n");
	fflush(stdout);

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

	printf("Sortie de add_sol\n");
	fflush(stdout);
}

void    ft_add_num_sol(t_sol *solutions, t_sol *to_add)
{
    t_sol   *tmp;
    
	printf("Entree dans add_num_sol\n");
	fflush(stdout);

    tmp = solutions;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = to_add;

	printf("Sortie de add_num_sol\n");
	fflush(stdout);
}
