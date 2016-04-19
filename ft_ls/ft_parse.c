/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:52:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/19 12:40:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void init_tab(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
}

int		*ft_parse(char **argv, char ***file_names)
{
	int		*options;
	int		i;
	int		j;

	i = 0;
	options = (int*)malloc(sizeof(int) * 5);
	init_tab(options);
	while (*(++argv))
	{
		if ((*argv)[j = 0] == '-')
			while ((*argv)[++j])
			{
				options[0] = ((*argv)[j] == 'R' || options[0] == 1) ? 1 : 0;
				options[1] = ((*argv)[j] == 't' || options[1] == 1) ? 1 : 0;
				options[2] = ((*argv)[j] == 'l' || options[2] == 1) ? 1 : 0;
				options[3] = ((*argv)[j] == 'r' || options[3] == 1) ? 1 : 0;
				options[4] = ((*argv)[j] == 'a' || options[4] == 1) ? 1 : 0;
				if ((*argv)[j] != 'a' && (*argv)[j] != 'l' &&
					(*argv)[j] != 82 && (*argv)[j] != 'r' && (*argv)[j] != 't')
					return (NULL);
			}
		else
			(*file_names)[i++] = strdup(*argv);
	}
	(*file_names)[i] = NULL;
	return (options);
}
