/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:01:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/21 10:13:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_create_path(t_room *room)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	new->room = room;
	new->next = NULL;
	new->coeff = 0;
	return (new);
}
