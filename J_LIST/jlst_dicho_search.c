// HEADER

#include "j_list.h"

int			*jlst_dicho_appears(j_list *list, void *data_ref, int (*compare_func)(void*, void*))
{
	int		index;
	int		cmp;
	int		last_gap;
	j_list	*tmp;

	last_gap = jlst_length(list) / 2;
	index = last_gap;
	tmp = jlst_get_node(list, last_gap);
	while (tmp && last_gap)
	{
		last_gap /= 2;
		cmp = compare_func(data_ref, tmp->data);
		if (!cmp)
			return (1);
		else if (cmp == 1)
			index += last_gap;
		else if (cmp == -1)
			index -= last_gap;
		tmp = jlst_get_node(list, index);
	}
	return (0);
}