/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:47:35 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 15:47:34 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

void	ft_main(char *file_name)
{
	t_superform *super;
	t_superform *solution;
	char		*tmp;

	tmp = (char*)malloc(sizeof(char) * 600);
	if (ft_launch_check(file_name))
	{
		super = ft_get_forms(file_name, &tmp);
		if (ft_count_forms(&super) == 0 || ft_count_forms(&super) > 26)
			ft_error();
		solution = ft_core(super);
		ft_display(solution);
	}
	else
		ft_error();
}
