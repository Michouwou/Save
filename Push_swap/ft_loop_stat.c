/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:24:59 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 10:26:31 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define _V (void*)-1

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
	int		z;

	i = 0;
	ret = 0;
	z = 0;
	while (i < size)
	{
		ret += tab[i];
		i++;
		if (!tab[i])
			z++;
	}
	return ((int)(ret / (size - z)));
}

static void	restart(int *loop, int *size, char **arg)
{
	*loop = -1;
	while (*loop != 0 && *loop != 1)
	{
		write(1, "\nSouhaitez-vous recommencer? (0 - non ; 1 - oui)\n", 49);
		*loop = -1;
		scanf("%d", loop);
		scanf("%*[^\n]");
	}
	if (loop)
		(*size)++;
	ft_bzero(*arg, ft_strlen(*arg));
}

static void	init_vals(t_stack **s_one, t_stack **s_two, char **arg)
{
	*s_one = NULL;
	*s_two = NULL;
	write(1, "\033[4mArguments?\n\033[0m", 19);
	scanf(" %[^\n]", *arg);
}

void		ft_loop_stat(t_stack *s_one, t_stack *s_two, char *options)
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
		init_vals(&s_one, &s_two, &arg);
		s_one = ft_create_stack(ft_strsplit(arg, ' '), 1);
		if (!options[0] && s_one != (void*)-1)
			ft_check_doubles(s_one, 1);
		if ((size + 1) % 10 == 0)
			increase_tab(&sum, size + 1);
		sum[size] = s_one == _V ? 0 : ft_core(s_one, s_two, options);
		restart(&loop, &size, &arg);
	}
	ft_printf("Proportion coups / nombre d'arguments : %d\n",
		average(sum, size));
	free(arg);
	free(sum);
}
