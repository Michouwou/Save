/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_errno.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:55:16 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/02 18:03:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_errno(T_LIST *trail, char **print)
{
	char *result;

	result = strerror(errno);
	result = ft_set_length(trail, result);
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
			ft_strlen(result) - 1);
}
