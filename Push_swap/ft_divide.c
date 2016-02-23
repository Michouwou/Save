/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:30:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 16:34:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

char	ft_divide(t_stack *alpha, t_stack *beta, char *options)
{
	char	is_ext;
	int		i;

	i = 0;
	is_ext = 'a';
	if (options[0] == 'v' || options[1] == 'v' || options[2] == 'v'
			|| options[3] == 'v')
	{
		if (options[0] == 'x' || options[1] == 'x' || options[2] == 'x'
				|| options[3] == 'x')
			is_ext = 'y';
		else
			is_ext = 'w';
	}
	if (ft_cn(alpha) > 0.75 && alpha->len >= 6)
	{
		ft_beg_sort(alpha);
		if (is_ext == 'y' || is_ext == 'w')
			ft_printf("La liste etant deja presque triee, on classe les 
					elements approximativement dans l'ordre pour que le 
					restack soit plus rapide.\n")
	}
	while (i < (alpha->len % 2 == 0) ? alpha->len / 2 : alpha->len - 1)
		ft_push(alpha, beta, is_ext);
	ft_printf("On separe a en deux piles pour gagner du temps sur les 
			prochaines operations.\n");
	return (is_ext);
}
