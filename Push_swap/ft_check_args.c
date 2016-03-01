/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:54:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 14:31:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(int *prev_stack, int len, long nb, char *options)
{
	int flag;
	int i;

	i = -1;
	flag = 0;

	printf("\t\t\tEntree dans check_args, nb = %ld\n", nb);
	fflush(stdout);

	if (nb > 2147483647 || nb < -2147483648)
		ft_error(0);
	while (++i < len)
		if ((long)prev_stack[i] == nb)
			flag = 1;

	printf("\t\t\tCheck doublon ok, flag = %d\n", flag);
	fflush(stdout);

	if (flag && (options[0] == 'd' || options[1] == 'd'
				|| options[2] == 'd' || options[3] == 'd'))
		return (1);
	else if (flag)
	{
		printf("\t\t\tErreur, le nombre est deja dans la liste et l'option d est non-specifiee\n");
		fflush(stdout);

		ft_error(0);
		return(0);
	}
	else
		return (1);
}
