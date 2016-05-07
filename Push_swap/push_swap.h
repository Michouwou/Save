/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:37:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 15:37:30 by mlevieux         ###   ########.fr       */
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

t_list			*ft_new_list(void);
int				ft_get_options(char *options, char **args);
t_list			*ft_create_stack(char **args);
void			ft_r(t_list **stack);
void			ft_rr(t_list **stack);
void			ft_s(t_list **stack);
void			ft_p(t_list **stack_one, t_list **stack_two);
int				ft_get_fastest(t_list *stack_one, t_list *stack_two);
void			ft_move(t_list **stack_one, t_list **stack_two, int code_one, int code_two);

