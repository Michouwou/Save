/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:07:22 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 09:50:12 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_swap_e(t_stack *alpha, char is_ext)
{
	int tmp;

	tmp = alpha->stack[0];
	alpha->stack[0] = alpha->stack[1];
	alpha->stack[1] = tmp;
	if (is_ext == 'x')
		ft_printf("Les deux premiers elements de la pile %s ne sont pas dans l'ordre, on les swap!\n", alpha->name);
	return ((!ft_strcmp(alpha->name, "a")) ? "sa" : "sb");
}

char	*ft_dswap_e(t_stack *alpha, t_stack *beta, char is_ext)
{
	if (is_ext == 'x')
		is_ext = 'y';
	ft_swap_e(alpha, is_ext);
	ft_swap_e(beta, is_ext);
	if (is_ext == 'y')
		ft_printf("Les deux premiers elements des deux piles sont dans le mauvais ordre, on les inverse deux a deux.\n");
	return ("ss");
}

/**
 * La fonction suivante pose le premier élément de la pile stack
 * one au dessus de la pile stack two
 **/

char	*ft_push(t_stack *stack_one, t_stack *stack_two, char is_ext)
{
	int *tmp;
	int i;

	tmp = (int*)malloc(sizeof(int) * (stack_two->len + 1));
	i = 1;
	while (i < stack_two->len + 1)
	{
		tmp[i] = stack_two->stack[i - 1];
		i++;
	}
	tmp[0] = stack_one->stack[0];
	i = 1;
/*	while (i < stack_one->len)
	{
		stack_one->stack[i - 1] = stack_one->stack[i];
		i++;
}*/
	stack_one->stack = (stack_one->stack) + 1;
	stack_two->stack = tmp;
	(stack_one->len)--;
	(stack_two->len)++;
	if (is_ext == 'x')
		ft_printf("La pile b doit prendre la moitie des elements pour gagner de la vitesse puisqu'il y en a plus que trois, ou alors on remet la pile b sur la pile a car le tri est fini.\n");
	return (!ft_strcmp(stack_one->name, "a") ? "pb" : "pa");
}
