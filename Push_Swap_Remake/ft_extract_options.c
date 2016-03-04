/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:08:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 10:06:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_extract_options(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	ret = ft_strnew(5);
	i = 0;
	k = 0;
	while (argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j] != 0)
			if ((argv[i][j] == 'd' || argv[i][j] == 'v' || argv[i][j] == 'c' ||
				argv[i][j] == 'C' || argv[i][j] == 'x') && k < 5)
				ret[k++] = argv[i][j];
		i++;
	}
	argv = argv + i;
	return (ret);
}

void	ft_stop(void)
{
	ft_printf("Error\n");
	exit(0);
}
