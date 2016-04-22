/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:18:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 14:51:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_move_index(T_LIST **trail, int padding)
{
	while (*trail != NULL)
	{
		(*trail)->start_index += padding;
		(*trail)->end_index += padding;
		*trail = (*trail)->next;
	}
}
