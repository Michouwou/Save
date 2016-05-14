/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:03:35 by mlevieux          #+#    #+#             */
/*   Updated: 2015/11/28 17:14:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == (void*)0)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(content_size + 1);
		new_list->content = ft_memcpy(new_list->content,
				(void*)content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
