/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 13:48:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction indique uniquement si la liste passee en argument est triee ou non
 **/

int     ft_is_sorted(t_stack *alpha)
{
	t_stack	*tmp;
	tmp = alpha;

	printf("Entree dans is_sorted, changement necessaires pour que alpha puisse etre nulle\n");
	fflush(stdout);

	while (tmp->next)
	{
		if (tmp->element < tmp->next->element)
			tmp = tmp->next;
		else
			return(0);
	}

	printf("Nous sortons de la boucle de is_sorted, nous allons donc renvoyer 1\n");
	fflush(stdout);

	return (1);
}
