/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:25:15 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/31 14:55:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_move(t_ant *ant)
{
	write(1, "L", 1);
	ft_putnbr(ant->number);
	write(1, "-", 1);
	write(1, ant->actual->name, ft_strlen(ant->actual->name));
}
