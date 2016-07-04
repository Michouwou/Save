/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:27:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:27:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void	jlst_push_front(j_list **first_node, void *data, size_t data_size, char alloc_)
{
	j_list	*node;
	j_list	*tmp;

	if (first_node)
	{
		node = jlst_node();
		node->list_len = first_node && *first_node ? (*first_node)->list_len + 1 : 1;
		node->data = data;
		node->state = 1;
		node->alloc_ = alloc_;
		node->data_len = data_size;
		if (*first_node)
		{
			node->next = *first_node;
			(*first_node)->previous = node;
			tmp = node;
			while ((tmp = tmp->next) != NULL)
				++(tmp->list_len);
		}
		*first_node = node;
	}
}
