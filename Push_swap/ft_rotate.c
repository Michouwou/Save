/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:06:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 12:03:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate(t_stack *alpha, char is_ext)
{
	int i;
	int tmp;

	i = 1;
	tmp = alpha->stack[0];
	while (i < alpha->len)
	{
		alpha->stack[i - 1] = alpha->stack[i];
		i++;
	}
	alpha->stack[alpha->len - 1] = tmp;
	if (is_ext == 'x')
		ft_printf("Les deux premiers elements de %s sont tries et les elements 
				non tries les plus proches sont dans la premiere moitie de 
				la pile donc on parcours vers le bas.\n", alpha->name);
	return (!ft_strmp(alpha->name, "a") ? "ra" : "rb");
}

char	*ft_drotate(t_stack *alpha, t_stack *beta, char is_ext)
{
	if (is_ext == 'x')
		is_ext = 'y';
	ft_rotate(alpha);
	ft_rotate(beta);
	if (is_ext == 'y')
		ft_printf("Les deux premiers elements des deux piles sont dans l'ordre 
				et dans les deux cas les deux elements non tries les plus 
				proches sont dans la premiere moitie, on parcourt donc les 
				deux vers le bas.\n");
	return ("rr");
}

char	*ft_rrotate(t_stack *alpha, char is_ext)
{
	int i;
	int tmp;

	i = alpha->len - 1;
	tmp = alpha->stack[alpha->len - 1];
	while (i > 0)
	{
		alpha->stack[i] = alpha->stack[i - 1];
		i--;
	}
	alpha->stack[0] = tmp;
	if (is_ext == 'x')
		ft_printf("Les deux premiers elements de la liste %s sont tries et les deux premiers elements non tries sont dans la deuxieme moitie de la pile, on se deplace donc vers le \"haut\".\n", alpha->name);
	return (!ft_strcmp(alpha->name, "a") ? "rra" : "rrb");
}

char	*ft_drrotate(t_stack *alpha, t_stack *beta, char is_ext)
{
	if (is_ext == 'x')
		is_ext == 'y';
	ft_rrotate(alpha);
	ft_rrotate(beta);
	if (is_ext == 'y')
		ft_printf("Les deux premiers elements des deux piles sont dans l'ordre 
				et dans les deux cas les deux elements non tries les plus 
				proches sont dans la deuxieme moitie, on parcourt donc les 
				deux vers le bas.\n");
	return ("rrr");
}
