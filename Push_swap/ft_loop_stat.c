/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:24:59 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 15:43:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	increase_tab(int **tab, int size)
{
	int		i;
	int		*new;

	i = 0;
	new = (int*)malloc(sizeof(int) * (size + 10));
	while (i < size)
	{
		new[i] = (*tab)[i];
		i++;
	}
	if (size > 0)
		free(*tab);
	*tab = new;
}

static int	average(int *tab, int size)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += tab[i];
		i++;
	}
	return ((int)(ret / size));
}

void	ft_loop_stat(t_stack *stack_one, t_stack *stack_two, char *options)
{
	int		size;
	int		*sum;
	int		loop;
	char	*arg;

	loop = 1;
	size = 0;
	sum = NULL;
	increase_tab(&sum, size);
	arg = ft_strnew(100);
	while (loop)
	{
		loop = 0;
		stack_one = NULL;
		stack_two = NULL;
		printf("Arguments?\n");fflush(stdout);
		scanf(" %[^\n]", arg);
		stack_one = ft_create_stack(ft_strsplit(arg, ' '));
		if ((size + 1) % 10 == 0)
			increase_tab(&sum, size + 1);
		sum[size] = ft_core(stack_one, stack_two, options);
		loop = -1;
		while (loop != 0 && loop != 1)
		{
			printf("\nSouhaitez-vous recommencer? (0 - non ; 1 - oui)\n");
			scanf("%d", &loop);
		}
		size++;
		ft_bzero(arg, ft_strlen(arg));
	}
	printf("Proportion coups / nombre d'arguments : %d\n", average(sum, size));
}
