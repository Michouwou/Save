/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_greatest_modifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:52:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 10:30:03 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_greatest_modifier(char *fmt, int *i, T_LIST *trail)
{
	free(trail->mod);
	if (fmt[*i] == 'j')
		trail->mod = ft_strdup("j");
	else if (fmt[*i] == 'z')
		trail->mod = ft_strdup("z");
	else if (fmt[*i] == 'l' && fmt[*i + 1] == 'l')
	{
		(*i)++;
		trail->mod = ft_strdup("ll");
	}
	else if (fmt[*i] == 'l' && fmt[*i + 1] != 'l' &&
		ft_strcmp(trail->mod, "ll"))
		trail->mod = ft_strdup("l");
	else if (fmt[*i] == 'h' && fmt[*i + 1] != 'h' &&
		trail->mod[0] != 'l')
		trail->mod = ft_strdup("h");
	else if (fmt[*i] == 'h' && fmt[*i + 1] == 'h' && trail->mod[0] == '-')
	{
		(*i)++;
		trail->mod = ft_strdup("hh");
	}
}
