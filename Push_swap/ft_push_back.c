#include "push_swap.h"

void	ft_push_back(t_stack **stack, t_stack *to_add)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = to_add;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
}