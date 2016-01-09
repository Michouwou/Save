/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:31:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/08 15:18:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"
#define NOW fflush(stdout);

t_list	*ft_first_node()
{
	t_list	*first;

	first = (t_list*)malloc(sizeof(t_list));
	first->next = NULL;
	first->location = -1;
	return (first);
}
void	ft_add_location(t_list **node, int location)
{
	(*node)->next = (t_list*)malloc(sizeof(t_list));
	*node = (*node)->next;
	(*node)->next = NULL;
	(*node)->location = location;
}

t_list	*ft_find_form(wchar_t *format)
{
	t_list *tmp;
	t_list *start;
	int i;

	start = ft_first_node();
	tmp = start;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			ft_add_location(&tmp, i);
		}
		i++;
	}
	return (start->next);
}
