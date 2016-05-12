/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths_coeff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:07:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 16:32:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_paths_coeff(t_path **paths, int number_of_ants)
{
	int	var;
	int	i;

	i = 0;
	var = 0;
	while (paths[i])
	{
		var += ft_path_len(paths[i]);
		i++;
	}
	if ((var + number_of_ants) % 2 == 1)
		++var;
	var = (var + number_of_ants) / i;
	i = 0;
	while (paths[i])
	{
		paths[i]->coeff = var - ft_path_len(paths[i]);
		printf("Le chemin %d a maintenant un coefficient de %d\n", i, paths[i]->coeff);
		i++;
	}
	printf("Un coeff est maintenan associe a %d chemins\n", i);
}
