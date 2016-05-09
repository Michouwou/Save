/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:37:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 11:37:31 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define SAY(m) printf(m);fflush(stdout);
#include <stdio.h>
typedef struct	s_stack
{
	long int			number;
	int					index;
	char				*str_rep;
	struct s_stack		*next;
}				t_stack;

t_stack			*ft_new_stack(int num, int index);
int				ft_get_options(char *options, char **args);
t_stack			*ft_create_stack(char **args);
void			ft_r(t_stack **stack);
void			ft_rr(t_stack **stack);
void			ft_s(t_stack **stack);
void			ft_p(t_stack **stack_one, t_stack **stack_two);
int				ft_get_min(t_stack *stack_one);
void			ft_move(t_stack **stack_one, int direction, int index, char **sols);
void			ft_repush(t_stack **stack_two, t_stack **stack_one, char **sols);
void			ft_core(t_stack *stack_one, t_stack *two, char *options);
void			ft_display(char *sols, char *options, t_stack *first);
int				ft_is_sorted(t_stack *stack);
int				ft_direction(t_stack *stack, int index);
char			*ft_strjoin_free(char *stra, char *strb);
void			ft_special_case(t_stack *stack_one, char *options);
void			ft_error(int error_code, char *str);
void			ft_push_back(t_stack **first, t_stack *to_add);
void			ft_check_doubles(t_stack *first);
