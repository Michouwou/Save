#include "push_swap.h"

void	ft_move(t_stack **stack, int direction, int index, char **sols)
{
	int	i;

	i = 0;
	if (direction == 1)
		while ((*stack)->index != index)
		{
			ft_r(stack);
			*sols = ft_strjoin_free(*sols, " ra");
		}
	else
		while ((*stack)->index != index)
		{
			ft_rr(stack);
			*sols = ft_strjoin_free(*sols, " rra");
		}
}