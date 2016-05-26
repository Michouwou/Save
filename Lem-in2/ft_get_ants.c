/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:25:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/26 10:03:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_get_ants(char ***args, int *number_of_ants, t_ant ***ants)
{
	int		tmp;

	tmp = ft_atoi((*args)[0]);
	if (tmp == 0)
		ft_block("No ants, then no one to cross the lem");
	*ants = (t_ant**)malloc(sizeof(t_ant*) * tmp + 1);
	*number_of_ants = tmp;
	tmp = 0;
	while (tmp < *number_of_ants)
	{
		(*ants)[tmp] = ft_create_ant(tmp + 1);
		tmp++;
	}
	(*args)++;
}
