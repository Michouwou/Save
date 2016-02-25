/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:04:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 13:35:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_make_colors(void)
{
	char	**res;
	int		i;

	i = 1;
	res = (char**)malloc(sizeof(char*) * 11);
	res[0] = ft_strnew(1);
	res[0] = "0";
	while (i < 11)
		res[i++] = ft_strnew(2);
	res[1] = "31";
	res[2] = "31";
	res[3] = "32";
	res[4] = "32";
	res[5] = "33";
	res[6] = "33";
	res[7] = "34";
	res[8] = "35";
	res[9] = "36";
	res[10] = "37";
	return (res);
}

char	**ft_make_ops(void)
{
	char	**res;
	int		i;

	i = 0;
	res = (char**)malloc(sizeof(char*) * 11);
	while (i < 11)
		res[i] = ft_strnew(3);
	res[0] = "ss";
	res[1] = "sa";
	res[2] = "sb";
	res[3] = "rra";
	res[4] = "rrb";
	res[5] = "ra";
	res[6] = "rb";
	res[7] = "pa";
	res[8] = "pb";
	res[9] = "rr";
	res[10] = "rrr";
	return (res);
}
