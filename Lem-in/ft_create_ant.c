/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:25:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 14:26:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ft_create_ant(int number)
{
	t_ant	*new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->number = number;
	new->actual = NULL;
	new->path = NULL;
	return (new);
}
