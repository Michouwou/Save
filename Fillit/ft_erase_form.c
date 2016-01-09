/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:44:24 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 11:43:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

void	ft_erase_form(t_superform *result, int form)
{
	result->points[form].id_form = -1;
	result->points[form + 1].id_form = -1;
	result->points[form + 2].id_form = -1;
	result->points[form + 3].id_form = -1;
}
