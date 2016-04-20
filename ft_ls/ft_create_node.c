/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:38:17 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 16:17:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tree	*ft_create_node(void)
{
	t_tree	*new;

	new = (t_tree*)malloc(sizeof(t_tree));
	new->data = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
