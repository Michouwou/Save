/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:40:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/22 11:24:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_set_width(wchar_t *result, T_LIST *trail)
{
	int i;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != 0)
		i++;
	if (trail->width > ft_wstrlen(result))
	{
		printf("\t\tOn est bien dans la condition\n");
		NOW
		if (!(trail->minus))
		{
			printf("\t\tOui toujours... %d\n", (int)(trail->width - ft_wstrlen(result) - 1));
			NOW
			if (trail->z_pad && !(trail->accuracy != -1 && trail->type == 'd'))
			{
				result = ft_repstr(result, i, i,
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result) - 1),
					trail->width - ft_wstrlen(result) - 1, '0'));
				printf("\t\tReponse?\n");
				NOW
			}
			else{
				printf("Mdr, bon bah on pas entre dans la fonction pour le z_pad\n");
				NOW
				result = ft_repstr(result, i, i,
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result) - 1),
					trail->width - ft_wstrlen(result) - 1, ' '));}
		}
		else
			result = ft_repstr(result, ft_wstrlen(result), ft_wstrlen(result),
					ft_wstrset(ft_wstrnew(trail->width - ft_wstrlen(result) - 1),
					trail->width - ft_wstrlen(result) - 1, ' '));
	}
	printf("\t\tOn va retourner set_width\n");
	NOW
	return (result);
}
