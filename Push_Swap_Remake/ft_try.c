
#include "push_swap.h"

t_sol   *ft_try_ab(t_stack *alpha, t_stack *beta, int prev_len)
{
    t_sol *solutions;
    
    solutions = ft_new_sol();
    while (ft_is_sorted(alpha) == 0 && ft_is_sorted(beta) == 0 &&
    solutions->len < prev_len)
    {
        if (alpha->number > alpha->next->number)
            ft_add_sol(solutions, ft_sa(alpha));
        if (beta->number < beta->next->number)
            ft_add_sol(solutions, ft_sa(beta));
        if (ft_direction(alpha) && ft_direction(beta))
            ft_add_sol(solutions, ft_rr(alpha, beta));
        if (ft_direction(alpha) && !ft_direction(beta))
        {
            ft_add_sol(solutions, ft_ra(alpha));
            ft_add_sol(solutions, ft_rra(beta));
        }
        if (!ft_direction(alpha) && ft_direction(beta))
        {
            ft_add_sol(solutions, ft_rra(alpha));
            ft_add_sol(solutions, ft_ra(beta));
        }
        if (!ft_direction(alpha) && !ft_direction(beta))
            ft_add_sol(solutions, ft_rrr(alpha, beta));
    }
    ft_add_num_sol(solutions, ft_restack(alpha, beta));
    return (solutions);
}

t_sol   *ft_atob(t_stack *alpha, t_stack *beta, int trans_len, int prev_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;
    solutions = ft_new_sol();
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(alpha, beta));
    ft_add_num_sol(solutions, ft_try_ab(alpha, beta, prev_len));
    return (solutions);
}

t_sol   *ft_btoa(t_stack *alpha, t_stack *beta, int trans_len, int prev_len)
{
    int     i;
    t_sol   *solutions;
    
    i = 0;
    solutions = ft_new_sol();²
    while (i < trans_len)
        ft_add_sol(solutions, ft_pa(beta, alpha));
    ft_add_num_sol(solutions, ft_try_ab(alpha, beta, prev_len));
    return (solutions);
}




