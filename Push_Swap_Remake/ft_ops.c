/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 11:24:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack *ft_create_element(char name)
{
	t_stack *new;

	printf("On est bien dans la creation d'un element\n");
	fflush(stdout);
	new = (t_stack*)malloc(sizeof(t_stack));
	new->element = 0;
	new->first = 1;
	new->next = new;
	new->prev = new;
	new->name = ft_strnew(1);
	new->name = ft_strcpy(new->name, name == 'a' ? "a" : "b");
	return (new);
}

void    ft_add_number(t_stack **alpha, int number)
{
	t_stack *tmp;

	
	printf("creation d'element OK\n");
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
}

char    *ft_ra(t_stack *alpha)
{
	alpha->first = 0;
	alpha = alpha->next;
	alpha->first = 1;
	return (!ft_strcmp(alpha->name, "a") ? "ra" : "rb");
}

char    *ft_rr(t_stack *alpha, t_stack *beta)
{
	ft_ra(alpha);
	ft_ra(beta);
	return ("rr");
}

char    *ft_rra(t_stack *alpha)
{
	alpha->first = 0;
	alpha = alpha->prev;
	alpha->first = 1;
	return (!ft_strcmp(alpha->name, "a") ? "rra" : "rrb");
}

char    *ft_rrr(t_stack *alpha, t_stack *beta)
{
	ft_rra(alpha);
	ft_rra(beta);
	return ("rrr");
}

char    *ft_sa(t_stack *alpha)
{
	t_stack *tmp1;
	t_stack *tmp2;
	t_stack *tmp3;

	tmp1 = alpha->prev;
	tmp2 = alpha->next;
	tmp3 = tmp2->next;
	tmp1->next = tmp2;
	alpha->prev = tmp2;
	alpha->next = tmp3;
	tmp2->prev = tmp1;
	tmp2->next = alpha;
	tmp3->prev = alpha;
	return (!ft_strcmp(alpha->name, "a") ? "sa" : "sb");
}

char    *ft_ss(t_stack *alpha, t_stack *beta)
{
	ft_sa(alpha);
	ft_sa(beta);
	return ("ss");
}

char    *ft_pa(t_stack *alpha, t_stack *beta)
{
	alpha->next->prev = alpha->prev;
	alpha->prev->next = alpha->next;
	alpha->next = beta;
	alpha->prev = beta->prev;
	beta->prev->next = alpha;
	beta->prev = alpha;
	return (!ft_strcmp(alpha->name, "b") ? "pb" : "pa");
}

char	*ft_move(t_stack *alpha, t_stack *beta)
{
	if (alpha->element > alpha->next->element &&
			beta->element < beta->next->element)
		return (ft_ss(alpha, beta));
	else if (alpha->element > alpha->next->element)
		return (ft_sa(alpha));
	else if (beta->element < beta->next->element)
		return(ft_sa(beta));
	else if (ft_direction(alpha) && ft_direction(beta))
		return (ft_rr(alpha, beta));
	else if (ft_direction(alpha))
		return (ft_ra(alpha));
	else if (ft_direction(beta))
		return (ft_ra(beta));
	else if (!ft_direction(alpha))
		return (ft_rra(alpha));
	else if (!ft_direction(beta))
		return (ft_rra(beta));
	else
		return (ft_rrr(alpha, beta));	
}
