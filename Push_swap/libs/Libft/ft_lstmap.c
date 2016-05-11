/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:30:02 by mlevieux          #+#    #+#             */
/*   Updated: 2015/11/28 16:19:03 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = ft_lstnew(NULL, 0);
	tmp->next = (*f)(lst);
	tmp2 = tmp;
	while (lst->next != NULL)
	{
		tmp = tmp->next;
		lst = lst->next;
		tmp->next = (*f)(lst);
	}
	(tmp->next)->next = NULL;
	tmp2 = tmp2->next;
	return (tmp2);
}
