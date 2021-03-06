// HEADER

#include "j_list.h"

j_list			*jlst_duplicate(j_list *first_node)
{
	j_list	*dup;
	j_list	*tmp;

	dup = jlst_new(jlst_length(first_node));
	tmp = first_node;
	while (tmp)
	{
		jlst_push(dup, jlst_datacpy(tmp->data), tmp->data_len, 1);
		tmp = tmp->next;
	}
	return (dup);
}