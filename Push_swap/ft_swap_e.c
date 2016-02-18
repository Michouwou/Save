#include "push_swap.h"

void    ft_swap_e(t_stack *alpha)
{
    int tmp;
    
    tmp = alpha->stack[0];
    alpha->stack[0] = alpha->stack[1];
    alpha->stack[1] = tmp;
}

void    ft_dswap_e(t_stack *alpha, t_stack *beta)
{
    ft_swap_e(alpha);
    ft_swap_e(beta);
}

/**
 * La fonction suivante pose le premier élément de la pile stack
 * one au dessus de la pile stack two
**/

void    ft_push(t_stack *stack_one, t_stack *stack_two)
{
    int *tmp;
    int i;
    
    tmp = (int*)malloc(sizeof(int) * (stack_two->len + 1));
    i = 1;
    while (i < stack_two->len + 1)
    {
        tmp[i] = stack_two->stack[i - 1];
        i++;
    }
    tmp[0] = stack_one->stack[0];
    i = 1;
    while (i < stack_one->len)
    {
        stack_one->stack[i - 1] = stack_one->stack[i];
        i++;
    }
    stack_two->stack = tmp;
    stack_one->len--;
    stack_two->len++;
}