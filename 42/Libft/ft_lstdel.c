/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:19:37 by mlevieux          #+#    #+#             */
/*   Updated: 2015/11/28 17:18:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list **tmp2;

	tmp2 = alst;
	while ((*alst)->next != NULL)
	{
		tmp = (*alst)->next;
		ft_lstdelone(&(*alst), (del));
		(*alst) = tmp;
	}
	ft_lstdelone(&(*alst), (del));
	*tmp2 = NULL;
}
