/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:31:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 09:45:31 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_char(char *options, char **args, int i, int j)
{
	if (args[i][j] == 'd')
		options[0] = 1;
	else if (args[i][j] == 'v')
		options[1] = 1;
	else if (args[i][j] == 'p')
		options[2] = 1;
	else if (args[i][j] == 'c')
		options[3] = 1;
	else
		ft_error(0, &(args[i][j]));
}

int			ft_get_options(char *options, char **args, int *is_stat)
{
	int	i;
	int	j;

	i = 1;
	while (args[i] && args[i][0] == '-' && !ft_isdigit(args[i][1]))
	{
		j = 1;
		if (!ft_strcmp(args[i], "--stat"))
			*is_stat = 1;
		else
			while (args[i][j])
			{
				test_char(options, args, i, j);
				j++;
			}
		i++;
	}
	return (i);
}
