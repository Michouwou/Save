/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:10:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 18:19:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**file_names;
	int		*options;
	int		i;

	file_names = (char**)malloc(sizeof(char*) * argc);
	i = 0;
	options = ft_parse(argv, &file_names);
	while (file_names[i] != NULL)
	{
		ft_browse(file_names[i], options);
		//free(file_names[i]);
		i++;
	}
	//free(file_names);
	return (0);
}
