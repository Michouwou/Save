// HEADER

#include "j_list.h"

int		jlst_appears(j_list *first_node, void *data, int (*compare_func)(void*, void*))
{
	j_list	*tmp;

	tmp = first_node;
	while (tmp)
	{
		if (!compare_func(data, tmp->data))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}