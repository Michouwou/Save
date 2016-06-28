// HEADER

#include "j_list.h"

void			jlst_add_data(j_list **first_node, int index, void *data, size_t data_len)
{
	j_list	*node;

	node = jlst_full_node(data, data_len, 0);
	jlst_add(first_node, index, node, 0);
}