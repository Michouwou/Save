/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:04:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:35:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_display_u(char **sols)
{
	write(1, "\n", 1);
}

void		ft_display(char *options, char **sols)
{
	if (options[0] == 'c' || options[1] == 'c' ||
			options[2] == 'c' || options[3] == 'c')
	{
		if (options[0] != 'x' && options[1] != 'x' &&
				options[2] != 'x' && options[3] != 'x')
			write(1, "COLOR", 5);
		else
			ft_display_u(sols);
	}
	else
	{
		while (*(sols + 1) != NULL)
			ft_printf("%s ", (*sols)++);
		ft_printf("%s\n", *sols);
	}
}
