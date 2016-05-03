/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:52:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 15:52:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_free_list(T_LIST **start)
{
	if ((*start) != NULL && (*start)->next != NULL)
		ft_free_list(&(*start)->next);
	free(*start);
}
