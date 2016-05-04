/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:45:29 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 12:58:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*set_x_length(T_LIST *trail, char *result)
{
	char	*insert;

	if (ft_strlen(result) && trail->accuracy > (int)ft_strlen(result))
	{
		insert = ft_strset(ft_strnew(trail->accuracy - ft_strlen(result)),
				trail->accuracy - ft_strlen(result), '0');
		result = ft_repstr(result, 0, 0, insert);
		free(insert);
	}
	return (result);
}

char			*ft_set_length(T_LIST *trail, char *result)
{
	int		i;
	int		j;
	char	*insert;

	i = 0;
	j = -1;
	if (!ft_strcmp(result, "0") && !trail->accuracy && !trail->alternate)
		return (ft_strnew(1));
	if (trail->format == 'x' || trail->format == 'X')
		return (result = set_x_length(trail, result));
	while (result[++j] != 0)
		if (ft_isdigit(result[j]))
			i++;
	i = trail->accuracy - i;
	j = 0;
	while (!ft_isdigit(result[j]) && result[j] != 0)
		j++;
	insert = ft_strset(ft_strnew(i), i, '0');
	if ((trail->type == 'd' || trail->type == 'p') && i > 0)
		result = ft_repstr(result, j, j, insert);
	free(insert);
	if (trail->type == 'S' && trail->accuracy != -1)
		result[trail->accuracy - (trail->accuracy % trail->oct_num)] = 0;
	else if (trail->type == 's')
		result[trail->accuracy] = 0;
	return (result);
}
