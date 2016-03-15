/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:26:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 17:44:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_create_room(char *name, int is_end, int is_start)
{
	t_room	*new;

	new->name = ft_strdup(name);
	new->links = NULL;
	new->is_end = is_end;
	new->is_start = is_start;
	new->is_full = 0;
	return (new);
}
