//HEADER

#include "j_like_list.h"

j_list	*jlst_new(int size)
{
	j_list	*new;
	int		i;
	
	i = 0;
	new = jlst_node();
	new->list_len = size;
	while (i < size - 1)
	{
		new->next = jlst_node();
		new->next->previous = new;
		new = new->next;
		new->list_len = size;
		i++;
	}
	new->next = NULL;
	while (new->previous)
		new = new->previous;
	return (new);
}