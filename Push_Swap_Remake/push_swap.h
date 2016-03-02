
#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include "libftprintf.h"
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct  s_stack
{
    int             element;
    int             first;
    struct s_stack  *next;
    struct s_stack  *prev;
    char            *name;
}               t_stack;

typedef struct  s_sol
{
    char    *operations;
    int     len;
}               t_sol;

t_stack *ft_create_element(char name);
void    ft_add_number(t_stack *alpha, int number);
t_sol   *ft_core(t_stack *alpha, t_stack *beta, char *options);
t_sol   *ft_try_ab(t_stack *alpha, t_stack *beta, int prev_len);
t_sol   *ft_atob(t_stack *alpha, t_stack *beta, int trans_len, int prev_len);
t_sol   *ft_btoa(t_stack *alpha, t_stack *beta, int prev_len);
int     *ft_is_sorted(t_stack *alpha);
char    *ft_ra(t_stack *alpha);
char    *ft_rr(t_stack *alpha, *beta);
char    *ft_rra(t_stack *alpha);
char    *ft_rrr(t_stack *alpha, t_stack *beta);
char    *ft_sa(t_stack *alpha);
char    *ft_ss(t_stack *alpha, t_stack *beta);
char    *ft_pa(t_stack *alpha, t *beta);
void    ft_display(t_sol *solution, char *options);
t_sol   *ft_new_sol(void);
void    ft_add_sol(t_sol *solutions, char *sol);
void    ft_add_num_sol(t_sol *solutions, t_sol *sol);
