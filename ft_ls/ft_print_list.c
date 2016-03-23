/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:17:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 10:32:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_data *data)
{
	printf("%s  %d %s  %s  %ld %s %s\n", data->mode, data->links,
			data->user_name, data->group_name, data->size, data->date,
			data->name);
}
