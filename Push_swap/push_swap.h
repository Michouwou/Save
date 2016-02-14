
#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct  s_stack
{
    int len;
    int min;
    int max;
    int *stack;
};              t_stack

void    ft_swap_e(t_stack *alpha);
void    ft_dswap_e(t_stack *alpha, t_stack *beta);
void    ft_push(t_stack *stack_one, t_stack *stack_two);
void    ft_rotate(t_stack *alpha);
void    ft_drotate(t_stack *alpha, t_stack *beta);
void    ft_rrotate(t_stack *alpha);
void    ft_drrotate(t_stack *alpha, t_stack *beta);
t_stack *ft_fill_stack(char **args, int argc); // ?
void    ft_check_args(int *prev_stack, long nb, char *options);
t_stack ft_new_stack(); // ?
char    **ft_create_sol();
void    ft_stack_sol(char *sol, char **stack_sol);
void    ft_core(char **args, int argc);
double  ft_cn(t_stack *alpha);
double  ft_ci(double cn);
double  ft_cs(t_stack *alpha, t_stack *beta);
double  ft_cds(t_stack *alpha, t_stack *beta);
void    ft_next_op(t_stack *alpha, t_stack *beta, double *coeffs, char *options);
/* void    ft_color(? color);    /!\ Need to find how to print things with color /!\ */
void    ft_error(); // ?
char    *ft_extract_options(char **argv, int argc);

#endif