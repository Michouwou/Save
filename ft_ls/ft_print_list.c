/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:17:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 02:30:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_data *data)
{
	printf("%c%s  %*d\n"/* %*s  %*s  %*ld %s %*s %s %*s\n", */,data->is_dir ? 'd' : '-', data->mode, ft_max_width(&data, 1), data->links/*, ft_max_width(&data, 2), data->user_name, ft_max_width(&data, 3), data->group_name, ft_max_width(&data, 4), data->size, data->date_mon, ft_max_width(&data, 5), data->date_num, data->date_hour, ft_max_width(&data, 6), data->name*/);
}
