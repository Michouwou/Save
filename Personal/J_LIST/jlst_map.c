// HEADER

#include "j_list.h"

void			jlst_map(j_list *first_node, void (*function)(j_list *node))
{
	j_list	*tmp;
	j_list	*secure_;

	tmp = first_node;
	secure_ = first_node;
	while (tmp)
	{
		if (secure_)
			secure_ = secure_->next;
		function(tmp);
		tmp = secure_;
	}
}