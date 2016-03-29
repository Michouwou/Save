//HEADER

#include "j_like_list.h"

void	jlst_push_front(j_list **first_node, void *data)
{
	j_list	*node;
	
	node = jlst_node();
	node->list_len = (*first_node)->list_len + 1;
	node->data = data;
	node->state = 1;
	node->data_len = sizeof(data);
	node->next = *first_node;
	(*first_node)->previous = node;
	while ((*first_node)->next)
	{
		(*first_node)->list_len++;
		*first_node = (*first_node)->next; 
	}
	(*first_node)->list_len++;
	while ((*first_node)->previous)
		*first_node = (*first_node)->previous;
}