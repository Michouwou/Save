
#include "j_list.h"

void	jlst_push_back(j_list **first_node, void *data, size_t data_size, char alloc_)
{
	j_list	*node;
	j_list	*tmp;

	if (first_node)
	{	
		node = jlst_node();
		node->list_len = first_node && *first_node ? (*first_node)->list_len + 1 : 1;
		node->data = data;
		node->state = 1;
		node->data_len = data_size;
		node->alloc_ = alloc_;
		if (*first_node)
		{
			tmp = *first_node;
			while (tmp && tmp->next)
			{
				++(tmp->list_len);
				tmp = tmp->next;
			}
			++(tmp->list_len);
			node->previous = tmp;
			tmp->next = node;
		}
		else
			*first_node = node;
	}
}