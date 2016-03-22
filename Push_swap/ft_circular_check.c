/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circular_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:05:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 14:29:12 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_circular_check(t_stack *alpha)
{
	int	i;
	int	j;

//	printf("\t\tEntree dans circular_check\nalpha->len = %d\n", alpha->len);
	fflush(stdout);

	i = 0;
	j = 0;
	if (alpha->len <= 2)
		return (1);
	while (i < alpha->len - 1 && alpha->stack[i] <= alpha->stack[i + 1])
		i++;
	if (i == alpha->len - 1 && alpha->stack[i] > alpha->stack[0])
		return (1);
	++i;

//	printf("\t\tMiddle of circular_check, i = %d, alpha->len = %d\n", i , alpha->len);
	fflush(stdout);

	while (i < alpha->len - 1 && alpha->stack[i] <= alpha->stack[i + 1])
		i++;
//	printf("\t\t\t\ti = %d, [i] = %d\n", i, alpha->stack[i]);
	if (i != alpha->len - 1 || (i == alpha->len - 1 && alpha->stack[i] > alpha->stack[0]))
		return (0);

//	printf("\t\tCircular_check va renvoyer 1\n");
	fflush(stdout);
	return (1);
}

int		ft_middle_coeff(t_stack *alpha)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 11;

	while (++i <= alpha->len / 2)
		if (alpha->stack[i] > alpha->stack[i + 1] && k % 10 == 1)
			k--;
	while (i < alpha->len - 1)
	{
		if (alpha->stack[i] > alpha->stack[i + 1] && k >= 10)
			k -= 10;
		i++;
	}
//	printf("K %% 8 ====================== > %d\n", k%8);
	return (k % 8);
}
