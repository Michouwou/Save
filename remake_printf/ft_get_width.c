/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:53:04 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 15:53:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_width(char *location, int *counter, T_LIST *trail)
{
	int		i;
	char	*str;

	i = *counter;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->width = ft_atoi(str = ft_strsub(location, i, *counter - i));
	free(str);
	(*counter) -= 1;
}
