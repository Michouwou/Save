/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:03:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 14:27:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sol	*ft_create_sol(int size)
{
	t_sol	*ret;
	int		i;

	i = 0;
	ret = (t_sol*)malloc(sizeof(t_sol));
	ret->sols = (char**)malloc(sizeof(char*) * size);
	ret->len = 0;
	while (i < size)
	{
		ret->sols[i++] = ft_strnew(3);
		ret->len++;
	}
	return (ret);
}

void	ft_stack_sol(char *sol, t_sol **stack_sol)
{
	t_sol	*tsol;
	int		i;

	i = 0;
	//printf("Entree dans stack_sol, stack_sol->len = %d et sol = %s\n", (*stack_sol)->len, sol);
	fflush(stdout);
	tsol = ft_create_sol((*stack_sol)->len + 1);

	tsol->len = (*stack_sol)->len;
	while (i < (*stack_sol)->len)
	{
		tsol->sols[i] = ft_strcpy(tsol->sols[i], (*stack_sol)->sols[i]);

		i++;
	}
	tsol->sols[i] = ft_strcpy(tsol->sols[i], sol);
	tsol->len++;
	*stack_sol = tsol;
	//printf("Premiere operation encore: %s\n", (*stack_sol)->sols[0]);
	fflush(stdout);
}
