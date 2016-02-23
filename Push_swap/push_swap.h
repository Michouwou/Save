/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:52:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 14:02:29 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct	s_stack
{
	int		len;
	int		min;
	int		max;
	char	*name;
	int		*stack;
};				t_stack

typedef struct	s_sol
{
	int		len;
	char	**sols;
};				t_sol

char			*ft_swap_e(t_stack *alpha, char is_ext); // ?
char			*ft_dswap_e(t_stack *alpha, t_stack *beta, char is_ext); // ?
char			*ft_push(t_stack *stack_one, t_stack *stack_two, char is_ext); // ?
char			*ft_rotate(t_stack *alpha, char is_next); // ?
char			*ft_drotate(t_stack *alpha, t_stack *beta, char is_ext); // ?
char			*ft_rrotate(t_stack *alpha, char is_ext); // ?
char			*ft_drrotate(t_stack *alpha, t_stack *beta, char is_ext); // ?
t_stack			*ft_fill_stack(char **args, int argc, char *options); // ?
int				ft_check_args(int *prev_stack, int len, long nb, char *options); // ?
t_stack			ft_new_stack(void); // ?
t_sol			*ft_create_sol(int size); // ?
void			ft_stack_sol(char *sol, t_sol *stack_sol); // ?
void			ft_core(char **args, int argc); // ?
double			ft_cs(t_stack *alpha, t_stack *beta); // ?
double			ft_cds(t_stack *alpha, t_stack *beta); // ?
char			*ft_next_op_a(t_stack *alpha);
char			*ft_next_op_b(t_stack *beta);
char			*ft_dnext_op(t_stack *alpha, t_stack *beta, char is_ext);
void			ft_color(char *color, char *to_print); // ?
void			ft_error(void); // ?
char			*ft_extract_options(char **argv, int argc); // ?
void			ft_restack(t_stack *alpha, t_stack *beta); // ?
void			ft_normalize(t_stack *alpha);
void			ft_display(char *options, t_sol *sols); // ?
void			ft_color(char *color, char *to_print); // ?
int				ft_circular_check(t_stack *alpha); // ?
int				ft_middle_coeff(t_stack *alpha); // ?
double			ft_circular_coeff(t_stack *

#endif
