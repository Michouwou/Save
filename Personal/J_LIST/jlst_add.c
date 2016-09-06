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

static void	increase(j_list *node)
{
	++(node->list_len);
}

void	jlst_add(j_list **first_node, int index, j_list *full_node)
{
	j_list	*tmp;
	int		intmp;
	
	intmp = index;
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
			tmp->next->previous = full_node;
			full_node->next = tmp->next;
			full_node->previous = tmp;
			tmp->next = full_node;
			jlst_map(*first_node, &increase);
			jlst_del_node(first_node, intmp);
			if (jlst_get_size(*first_node) >= tmp->list_len * 2 / 3)
				jlst_resize(*first_node);
		}
	}
}
