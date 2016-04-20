/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:17:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 14:52:42 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_tree *node, int *width)
{
	printf("%c%s  %*d %*s  %*s  %*ld %s %*s %s %-*s\n", node->data->type, node->data->mode, width[6], node->data->links, width[5], node->data->user_name, width[4], node->data->group_name, width[3], node->data->size, node->data->date_mon, width[2], node->data->date_num, node->data->date_hour, width[0], node->data->name);
}
