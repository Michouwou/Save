// HEADER

#include "j_list.h"

size_t			jlst_get_total_size(j_list *first_node)
{
	size_t	total;
	j_list	*tmp;

	total = 0;
	tmp = first_node;
	while (tmp)
	{
		total += tmp->data_len;
		tmp = tmp->next;
	}
	return (total);
}