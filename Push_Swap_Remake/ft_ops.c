/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 16:19:49 by mlevieux         ###   ########.fr       */
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
	new->next = NULL;
	new->prev = NULL;
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
		printf("Affection de l'element\n");
		fflush(stdout);
		*alpha = ft_create_element('a');
		(*alpha)->element = number;

		printf("Affection de l'element OK\n");
		fflush(stdout);
	}
	else
	{
		tmp = ft_create_element((*alpha)->name[0]);
		tmp->next = *alpha;
		(*alpha)->prev = tmp;
		tmp->element = number;
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
	t_stack	*tmp;
	t_stack *tmp2;
	printf("ft_ra\n");
	fflush(stdout);

	tmp = *alpha;
	*alpha = (*alpha)->next;
	(*alpha)->prev = NULL;
	tmp->next = NULL;
	tmp2 = *alpha;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	return (!ft_strcmp((*alpha)->name, "a") ? "ra" : "rb");
}

char    *ft_rr(t_stack **alpha, t_stack **beta)
{
	ft_ra(alpha);
	ft_ra(beta);
	return ("rr");
}
char    *ft_rra(t_stack **alpha)
{	
	t_stack	*tmp;
	t_stack *tmp2;
	printf("ft_rra\n");
	fflush(stdout);

	tmp = *alpha;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *alpha;
	(*alpha)->prev = tmp;
	(*alpha) = tmp;
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

	t_stack *tmp;

	tmp = (*alpha)->next;
	(*alpha)->prev = tmp;
	(*alpha)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = (*alpha);
	*alpha = tmp;
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
	printf("ft_pa\n");
	fflush(stdout);
	if (!(*alpha)->next)
	{
		(*alpha)->next = *beta;
		printf("YO 1\n");
		fflush(stdout);
		(*beta)->prev = *alpha;
		printf("YO 2\n");
		fflush(stdout);
		*beta = *alpha;
		*alpha = NULL;
		(*beta)->name = ft_strcpy((*beta)->name, !ft_strcmp((*beta)->next->name, "a") ? "a" : "b");
		return ((*beta)->name[0] == 'b' ? "pa" : "pb");
	}
	else if (*beta)
	{
		tmp = *alpha;
		*alpha = (*alpha)->next;
		tmp->next = (*beta);
		(*beta)->prev = tmp;
		*beta = tmp;
		(*alpha)->prev = NULL;
		(*beta)->name = ft_strcpy((*beta)->name, !ft_strcmp((*alpha)->name, "a") ? "b" : "a");
	}
	else
	{
		*beta = *alpha;
		*alpha = (*alpha)->next;
		(*alpha)->prev = NULL;
		(*beta)->next = NULL;
		(*beta)->name = ft_strcpy((*beta)->name, "b");
	}
	return (!ft_strcmp((*alpha)->name, "b") ? "pb" : "pa");
}
