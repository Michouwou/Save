/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:41:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/21 11:18:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*ft_create_data(void)
{
	t_data	*new;

	new = (t_data*)malloc(sizeof(t_data));
	new->name = NULL;
	new->mode = NULL;
	new->type = '-';
	new->date_mon = NULL;
	new->date_num = NULL;
	new->date_hour = NULL;
	new->time = 0;
	new->size = 0;
	new->group_name = NULL;
	new->user_name = NULL;
	new->links = 0;
	new->is_dir = 0;
	new->permission = 1;
	new->path = NULL;
	return (new);
}
