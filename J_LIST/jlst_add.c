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

void	jlst_add(j_list **first_node, int index, void *data, size_t data_size, char alloc_)
{
	if (first_node && *first_node)
	{
		while ((*first_node)->next && index > 0)
		{
			*first_node = (*first_node)->next;
			index--;
		}
		if (index == 0)
		{
			(*first_node)->data = data;
			(*first_node)->data_len = data_size;
			(*first_node)->state = 1;
			(*first_node)->alloc_ = alloc_;
			if (jlst_get_size(*first_node) >= (*first_node)->list_len * 2 / 3)
				jlst_resize(first_node, 0);
		}
		while ((*first_node)->previous)
			*first_node = (*first_node)->previous;
	}
}
