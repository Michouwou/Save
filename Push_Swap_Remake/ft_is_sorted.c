/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:04:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction indique uniquement si la liste passee en argument est triee ou non
 **/

int     ft_is_sorted(t_stack *alpha)
{
	t_stack	*tmp;
	tmp = alpha->next;

	printf("Entree dans is_sorted, changement necessaires pour que alpha puisse etre nulle\n");
	fflush(stdout);

	while (tmp->next->first == 0)
	{
		ft_print_stack(alpha);
		if (tmp->prev->element < tmp->element && tmp->element < tmp->next->element)
			tmp = tmp->next;
		else
			return(0);
	}

	printf("Nous sortons de la boucle de is_sorted, nous allons donc renvoyer 1\n");
	fflush(stdout);

	return (1);
}
