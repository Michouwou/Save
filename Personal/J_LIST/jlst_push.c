// HEADER

#include "j_list.h"

void	jlst_push(j_list *list, void *data, size_t data_len, char alloc_)
{
	j_list	*tmp;

	if (list)
	{
		tmp = list;
		while (tmp && tmp->state)
			tmp = tmp->next;
		if (tmp && !tmp->state)
		{
			tmp->data = data;
			tmp->data_len = data_len;
			tmp->state = 1;
			tmp->alloc_ = alloc_;
		}
		else
		{
			tmp = jlst_full_node(data, data_len, alloc_);
			jlst_push_back(&list, data, data_len, alloc_);
		}
	}
}