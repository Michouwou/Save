/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:37:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 19:13:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	long int			number;
	int					index;
	struct s_list		*next;
}				t_list;

t_list			*ft_new_stack(int num, int index);
int				ft_get_options(char *options, char **args);
t_list			*ft_create_stack(char **args);
void			ft_r(t_list **stack);
void			ft_rr(t_list **stack);
void			ft_s(t_list **stack);
void			ft_p(t_list **stack_one, t_list **stack_two);
int				ft_get_min(t_stack *stack_one);
void			ft_move(t_stack **stack_one, int direction, int index, char **sols);
void			ft_repush(t_stack **stack_two, t_stack **stack_one);
void			ft_core(t_stack *stack_one, t_stack *two, char *options);
void			ft_display(char **sols);
void			ft_is_sorted(t_stack *stack);

