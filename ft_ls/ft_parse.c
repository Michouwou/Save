/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:52:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/22 17:27:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_parse(char **argv, char ***file_names)
{
	char	*options;
	int		i;
	int		j;

	i = 0;
	options = (char*)malloc(sizeof(char) * 5);
	while (*(++argv))
	{
		if ((*argv)[j = 0] == '-')
			while ((*argv)[++j])
			{
				options[0] = ((*argv)[j] == 'a' || options[0] == 1) ? 1 : 0;
				options[1] = ((*argv)[j] == 'l' || options[1] == 1) ? 1 : 0;
				options[2] = ((*argv)[j] == 'R' || options[2] == 1) ? 1 : 0;
				options[3] = ((*argv)[j] == 'r' || options[3] == 1) ? 1 : 0;
				options[4] = ((*argv)[j] == 't' || options[4] == 1) ? 1 : 0;
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
