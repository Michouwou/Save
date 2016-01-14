/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:31:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 18:20:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/* ************************************************************************** */
/*                                                                            */
/* Comments are just in case I decide to handle the '*' case, which would     */
/* make things a little more complicated, for example the user can give me :  */
/* --- "%#*.*d"                                                               */
/* That is, I would have to pass a copy of the arg list to the functions      */
/* looking for the format so that they could get the next argument in the     */
/* list with 'arg_index', the index of the knot itself!                       */
/*                                                                            */
/* ************************************************************************** */

int		ft_type_index(char *format, int location)
{
	int i;

	i = location + 1;
	while ((format[i] == '.' || ft_isdigit(format[i]) || ft_is_flag(format[i]) ||
			ft_is_mod(format[i])) && format[i] != '\0')
		i++;
	return (i);
}

char	ft_get_format(char *format, int location)
{
	return (format[ft_type_index(format, location)]);
}

T_LIST	*ft_first_node(void)
{
	T_LIST	*first;

	first = (T_LIST*)malloc(sizeof(T_LIST));
	first->next = NULL;
	//first->arg_index = 0;
	first->start_index = 0;
	first->end_index = 0;
	//first->is_star = 0;
	first->type = 0;
	first->format = 0;
	return (first);
}

void	ft_add_knot(T_LIST **node, int location, char *format)
{
	(*node)->next = (T_LIST*)malloc(sizeof(T_LIST));
	//(*node)->next->arg_index = (*node)->arg_index + 1;
	*node = (*node)->next;
	(*node)->next = NULL;
	(*node)->start_index = location;
	(*node)->end_index = ft_type_index(format, location);
	(*node)->format = ft_get_format(format, location);
	(*node)->type = ft_what_type((*node)->format);
	(*node)->flag = ft_get_flag(format, location);
	(*node)->width = ft_get_width(format, location);
	(*node)->accuracy = ft_get_accuracy(format, location);
	(*node)->mod = ft_get_mod(format, location, (*node)->end_index);
}

T_LIST	*ft_find_form(char *format/*, va_list args*/)
{
	T_LIST	*tmp;
	T_LIST	*start;
	int		i;

	start = ft_first_node();
	tmp = start;
	i = -1;
	while (format[++i] != '\0')
		if (format[i] == '%')
		{
			while(tmp->next != NULL)
				tmp = tmp->next;
			ft_add_knot(&tmp, i, format);
		}
	return (start->next);
}
