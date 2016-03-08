/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 16:08:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include "libftprintf.h"
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>

/**
 * Bon, a retenir, 1 c'est try_ab, 2 c'est atob, et 0 btoa
**/

typedef struct  s_stack
{
    int             element;
    struct s_stack  *next;
    struct s_stack  *prev;
    char            *name;
}               t_stack;

typedef struct  s_sol
{
    char            *operations;
    struct s_sol    *next;
}               t_sol;

int		ft_stack_med(t_stack *alpha);
t_stack *ft_create_element(char name);
void    ft_add_number(t_stack **alpha, int number);
void	ft_core(t_stack **alpha, t_stack **beta, t_sol **solutions, char *options);
int     ft_is_sorted(t_stack *alpha);
char    *ft_ra(t_stack **alpha);
char    *ft_rr(t_stack **alpha, t_stack **beta);
char    *ft_rra(t_stack **alpha);
char    *ft_rrr(t_stack **alpha, t_stack **beta);
char    *ft_sa(t_stack **alpha);
char    *ft_ss(t_stack **alpha, t_stack **beta);
char    *ft_pa(t_stack **alpha, t_stack **beta);
void    ft_display(t_sol *solution, char *options);
t_sol   *ft_new_sol(void);
void    ft_add_sol(t_sol **solutions, char *sol);
void    ft_add_num_sol(t_sol **solutions, t_sol *to_add);
t_sol	*ft_restack(t_stack **alpha, t_stack **beta);
char	*ft_extract_options(char **argv);
void	ft_stop(void);
int		ft_position(t_stack *beta);
void	ft_print_stack(t_stack *alpha);
t_stack	*ft_stack_copy(t_stack *alpha);
int		ft_stack_len(t_stack *alpha);
int		ft_stack_min(t_stack *alpha);
int		ft_stack_max(t_stack *alpha);
int		ft_circle_check(t_stack *alpha);
int		ft_direction(t_stack *alpha, int number);
int		ft_bposition(t_stack *alpha);
void	ft_ator(t_sol **solution);
#endif
