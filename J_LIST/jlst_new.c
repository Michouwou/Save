/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:25:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:25:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

j_list	*jlst_new(int size)
{
	j_list	*new;
	j_list	*tmp;
	int		i;
	
	i = 0;
	if (size < 1)
		return (NULL);
	new = jlst_node();
	new->list_len = size;
	tmp = new;
	while (i < size - 1)
	{
		tmp->next = jlst_node();
		tmp->next->previous = tmp;
		tmp = tmp->next;
		tmp->list_len = size;
		i++;
	}
	tmp->next = NULL;
	return (new);
}
