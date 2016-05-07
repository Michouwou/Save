/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:35:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 15:47:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_options(char *options, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i][0] == '-' && !ft_isdigit(args[i][1]))
	{
		j = 1;
		while (args[i][j])
		{
			if (args[i][j] == 'c')
				options[0] = 1;
			else if (args[i][j] == 'C')
				options[1] = 1;
			else if (args[i][j] == 'v')
				options[2] = 1;
			else if (args[i][j] == 'd')
				options[3] = 1;
			else if (args[i][j] == 't')
				options[4] = 1;
			else
				ft_error(1);
			j++;
		}
		i++;
	}
	return (i);
}
