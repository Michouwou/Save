/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:05:29 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:36:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_extract_options(char **argv, int argc)
{
	int		i;
	int		j;
	char	res;

	res = ft_strnew(4);
	while (**argv == '-' && argc > 1)
	{
		i = 0;
		while ((*argv)[++i] != 0)
		{
			j = 0;
			if ((*argv)[i] == 'v' || (*argv)[i] == 'x' ||
					(*argv)[i] == 'c' || (*argv)[i] == 'd')
			{
				while (j < 4 && res[j] != 0)
					if (res[j++] == (*argv)[i])
						ft_error();
				res[j] = (*argv)[i];
			}
			else
				ft_error();
		}
		argv++;
	}
	return (res);
}
