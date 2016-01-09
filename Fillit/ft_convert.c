/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:22:01 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/16 09:33:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

t_form	*ft_convert(t_superform *super, int id)
{
	t_form	*ret;
	int		i;

	i = 0;
	ret = ft_new_form(id);
	while (super->points[i].id_form != id)
		i++;
	i++;
	ft_form_add_point(ret, &super->points[i]);
	i++;
	ft_form_add_point(ret, &super->points[i]);
	i++;
	ft_form_add_point(ret, &super->points[i]);
	return (ret);
}
