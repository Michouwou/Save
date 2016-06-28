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

int		ft_is_number(char *str)
{
	int	i;
	int	zero;

	i = 1;
	zero = (str[0] == '0' || str[0] == '-' || str[0] == '+') ? 2 : 1;
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return (0);
	while (str[0] && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (str[i] != '0')
			zero = 1;
		i++;
	}
	return (zero);
}

void	ft_get_ants(char *str, int *number_of_ants, t_ant ***ants)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = ft_atoi(str);
	if (tmp == 0 && ft_is_number(str) == 1)
		ft_block("The number of ants cannot be out the limits of an int");
	if (tmp == 0)
		ft_block("No ants, then no one to cross the lem");
	if (tmp < 0)
		ft_block("The number of ants cannot be negative dude...");
	*ants = (t_ant**)malloc(sizeof(t_ant*) * (tmp + 1));
	*number_of_ants = tmp;
	tmp = 0;
	while (tmp < *number_of_ants)
	{
		(*ants)[tmp] = ft_create_ant(tmp + 1);
		tmp++;
	}
	(*ants)[tmp] = NULL;
}
