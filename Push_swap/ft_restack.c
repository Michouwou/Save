#include "push_swap.h"

void    ft_restack(t_stack *alpha, t_stack *beta)
{
    while (beta->len > 0)
    {
        while (beta->stack[0] < alpha->stack[0])
            if (alpha->stack[0] != alpha->min)
                ft_rrotate(alpha);
        while (beta->stack[0] > alpha->stack[0])
            if (alpha->stack[0] != alpha->max)
                ft_rotate(alpha);
        ft_push(beta, alpha);
        beta->len--;
        alpha->len++;
    }
}