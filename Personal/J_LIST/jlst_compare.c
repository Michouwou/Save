// HEADER

#include "j_list.h"

int				jlst_compare(j_list *node1, j_list *node2, int (*compare_func)(void*, void*))
{
	j_list	*tmpa;
	j_list	*tmpb;

	while (tmpa && tmpb)
	{
		if (compare_func(tmpa->data, tmpb->data))
			return (0);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	return (1);
}