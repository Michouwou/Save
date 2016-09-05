// HEADER

#include "j_list.h"

j_list			*jlst_full_node(void *data, size_t data_len, char alloc_)
{
	j_list	*node;

	node = jlst_node();
	node->data = data;
	node->data_len = data_len;
	node->alloc_ = alloc_;
	node->state = 1;
	return (node);
}