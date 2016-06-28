// HEADER

#include "j_list.h"

void			jlst_spec_map(j_list *first_node, void *data_ref, void (*function)(j_list *node), int (*compare_func)(void*, void*))
{
	j_list	*tmp;
	j_list	*secure_;

	tmp = first_node;
	secure_ = first_node;
	while (tmp)
	{
		tmp = secure_;
		secure_ = tmp->next;
		if (!compare_func(data_ref, tmp->data))
			function(tmp);
	}
}