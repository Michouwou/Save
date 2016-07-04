// HEADER

#include "j_list.h"

j_list	*jlst_get_node(j_list *list, void *data, int (*compare_func)(void*, void*))
{
	j_list	*tmp;

	tmp = list;
	while (tmp && compare_func(data, tmp->data))
		tmp = tmp->next;
	return (tmp ? tmp : NULL);
}