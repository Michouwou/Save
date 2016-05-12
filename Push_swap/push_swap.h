/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:37:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 10:19:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_stack
{
	long int			number;
	int					index;
	char				*str_rep;
	struct s_stack		*next;
}				t_stack;

t_stack			*ft_new_stack(char *str, int index, int code);
int				ft_get_options(char *options, char **args, int *is_stat);
t_stack			*ft_create_stack(char **args, int code);
void			ft_r(t_stack **stack);
void			ft_rr(t_stack **stack);
void			ft_s(t_stack **stack);
void			ft_p(t_stack **stack_one, t_stack **stack_two, int code);
int				ft_get_min(t_stack *stack_one);
void			ft_move(t_stack **stack, t_stack *stack_two, int dir_ind[],
					char **sols);
void			ft_repush(t_stack **stack_two, t_stack **stack_one,
					char **sols, int is_ext);
int				ft_core(t_stack *stack_one, t_stack *two, char *options);
int				ft_display(char *sols, char *options, t_stack *first);
int				ft_is_sorted(t_stack *stack);
int				ft_direction(t_stack *stack, int index);
char			*ft_strjoin_free(char *stra, char *strb);
int				ft_special_case(t_stack *stack_one, char *options);
void			ft_error(int error_code, char *str);
void			ft_push_back(t_stack **first, t_stack *to_add);
void			ft_check_doubles(t_stack *first, int is_stat);
void			ft_loop_stat(t_stack *stack_one, t_stack *stack_two,
					char *options);
void			ft_print_stack(t_stack *stack_one, t_stack *stack_two);
void			ft_free(t_stack *stack);
void			ft_error_loop(int code, char *str);

#endif
