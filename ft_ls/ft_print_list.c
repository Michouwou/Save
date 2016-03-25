/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:17:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:03:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_data **data, int index)
{
	printf("%c%s  %*d %*s  %*s  %*ld %s %*s %s %-*s\n", (data[index])->is_dir ? 'd' : '-', (data[index])->mode, ft_max_width(data, 1), (data[index])->links, ft_max_width(data, 2), (data[index])->user_name, ft_max_width(data, 3), (data[index])->group_name, ft_max_width(data, 4), (data[index])->size, (data[index])->date_mon, ft_max_width(data, 5), (data[index])->date_num, (data[index])->date_hour, ft_max_width(data, 6), (data[index])->name);
}
