#include "push_swap.h"

int		ft_direction(t_stack *stack, int index)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->index != index)
	{
		++i;
		tmp = tmp->next;
	}
	while (tmp)
	{
		--i;
		tmp = tmp->next;
	}
	if (i < 0)
		return (1);
	else
		return (2);
}