/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 15:22:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * Les deux fonctions suivantes creent et ajoutent un element a une pile
 **/

t_stack *ft_create_element(char name)
{
	t_stack *new;

	printf("On est dans la creation d'un element\n");
	fflush(stdout);
	
	new = (t_stack*)malloc(sizeof(t_stack));
	new->element = 0;
	new->first = 1;
	new->next = new;
	new->prev = new;
	new->name = ft_strnew(1);
	new->name = ft_strcpy(new->name, name == 'a' ? "a" : "b");
	
	printf("Fin de la creation\n");
	fflush(stdout);

	return (new);
}

void    ft_add_number(t_stack **alpha, int number)
{
	t_stack *tmp;

	
	printf("Ajout d'element\n");
	fflush(stdout);

	if (!*alpha)
	{
		*alpha = ft_create_element('a');
		(*alpha)->element = number;
		(*alpha)->first = 1;
		
		printf("Affection de l'element OK\n");
		fflush(stdout);
	}
	else
	{
		tmp = ft_create_element((*alpha)->name[0]);
		((*alpha)->prev)->next = tmp;
		tmp->prev = (*alpha)->prev;
		tmp->next = *alpha;
		(*alpha)->prev = tmp;
		tmp->element = number;
		(*alpha)->first = 0;
		*alpha = tmp;
	}
	
	printf("Sortie de la fonction d'ajout d'element\n");
	fflush(stdout);
}

/**
 * Les fonctions suivantes representent les operations que l'on effectue sur les piles
 **/

char    *ft_ra(t_stack **alpha)
{
	printf("ft_ra\n");
	fflush(stdout);

	(*alpha)->first = 0;
	*alpha = (*alpha)->next;
	(*alpha)->first = 1;
	return (!ft_strcmp((*alpha)->name, "a") ? "ra" : "rb");
}

char    *ft_rr(t_stack **alpha, t_stack **beta)
{	
	printf("ft_rr\n");
	fflush(stdout);

	ft_ra(alpha);
	ft_ra(beta);
	return ("rr");
}

char    *ft_rra(t_stack **alpha)
{	
	printf("ft_rra\n");
	fflush(stdout);

	(*alpha)->first = 0;
	*alpha = (*alpha)->prev;
	(*alpha)->first = 1;
	return (!ft_strcmp((*alpha)->name, "a") ? "rra" : "rrb");
}

char    *ft_rrr(t_stack **alpha, t_stack **beta)
{	
	printf("ft_rrr\n");
	fflush(stdout);

	ft_rra(alpha);
	ft_rra(beta);
	return ("rrr");
}

char    *ft_sa(t_stack **alpha)
{	
	printf("ft_sa\n");
	fflush(stdout);

	t_stack *tmp1;
	t_stack *tmp2;
	t_stack *tmp3;

	tmp1 = (*alpha)->prev;
	tmp2 = (*alpha)->next;
	tmp3 = tmp2->next;
	tmp1->next = tmp2;
	(*alpha)->prev = tmp2;
	(*alpha)->next = tmp3;
	tmp2->prev = tmp1;
	tmp2->next = *alpha;
	tmp3->prev = *alpha;
	(*alpha)->first = 0;
	(*alpha)->prev->first = 1;
	*alpha = (*alpha)->prev;
	return (!ft_strcmp((*alpha)->name, "a") ? "sa" : "sb");
}

char    *ft_ss(t_stack **alpha, t_stack **beta)
{	
	printf("ft_ss\n");
	fflush(stdout);

	ft_sa(alpha);
	ft_sa(beta);
	return ("ss");
}

char    *ft_pa(t_stack **alpha, t_stack **beta)
{	
	t_stack *tmp;
	t_stack	*tmp2;
	printf("ft_pa\n");
	fflush(stdout);

	tmp = (*alpha)->next;
	tmp2 = (*alpha)->prev;
	tmp->prev = tmp2;;
	tmp2->next = tmp;
	(*alpha)->next = *beta;
	(*beta)->first = 0;
	(*alpha)->prev = (*beta)->prev;
	(*beta)->prev->next = *alpha;
	(*beta)->prev = *alpha;
	*beta = *alpha;
	(*alpha) = tmp;
	(*alpha)->first = 1;
	return (!ft_strcmp((*alpha)->name, "b") ? "pb" : "pa");
}

/**
 * La fonction suivante effectue l'operation la plus appropriee a l'etat de la pile
 **/

char	*ft_move(t_stack **alpha, t_stack **beta)
{
	printf("Entree dans ft_move\n");
	fflush(stdout);

	if ((*alpha)->element > (*alpha)->next->element &&
			(*beta)->element < (*beta)->next->element)
		return (ft_ss(alpha, beta));
	else if ((*alpha)->element > (*alpha)->next->element)
		return (ft_sa(alpha));
	else if ((*beta)->element < (*beta)->next->element)
		return(ft_sa(beta));
	else if (ft_direction(*alpha) && ft_direction(*beta))
		return (ft_rr(alpha, beta));
	else if (ft_direction(*alpha))
		return (ft_ra(alpha));
	else if (ft_direction(*beta))
		return (ft_ra(beta));
	else if (!ft_direction(*alpha))
		return (ft_rra(alpha));
	else if (!ft_direction(*beta))
		return (ft_rra(beta));
	else
		return (ft_rrr(alpha, beta));	
}
