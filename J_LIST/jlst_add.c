/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:26:16 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:27:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void	jlst_add(j_list **first_node, int index, j_list *full_node, char alloc_)
{
	j_list	*tmp;
	
	if (first_node && *first_node)
	{
		tmp = *first_node;
		while (tmp->next && index > 0)
		{
			tmp = tmp->next;
			index--;
		}
		if (index == 0)
		{
			tmp->data = full_node->data;
			tmp->data_len = full_node->data_len;
			tmp->state = 1;
			tmp->alloc_ = full_node->alloc_;
			if (jlst_get_size(*first_node) >= tmp->list_len * 2 / 3)
				jlst_resize(first_node);
			free(full_node);
		}
	}
}
