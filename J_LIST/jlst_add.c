//HEADER

#include "j_like_list.h"

void	jlst_add(j_list **first_node, int index, void *data)
{
	while (index > 1)
	{
		*first_node = (*first_node)->next;
		index--;
	}
	(*first_node)->data = data;
	(*first_node)->data_len = (int)sizeof(data);
	(*first_node)->state = 1;
	while ((*first_node)->previous)
		*first_node = (*first_node)->previous;
	if (jlst_get_size(first_node) >= (*first_node)->list_len * (2 / 3))
		jlst_resize(first_node);
}