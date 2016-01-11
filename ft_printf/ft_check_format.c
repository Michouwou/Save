/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:43:12 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 12:26:01 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_zero(int *flag, int *dot, int *mod)
{
	*dot = 0;
	*mod = 0;
	*flag = 0;
}

static void		ft_inner_loop(int tab[], char *format, int *i)
{
	while (!ft_what_type(format[*i]) && format[*i] != 0)
	{
		if (ft_is_flag(format[*i]) && !tab[2] && !tab[1] && !tab[0])
			tab[0] = 1;
		else if (format[*i] == '.' && ft_isdigit(format[*i + 1]) &&
				!tab[2] && !tab[1])
			tab[1] = 1;
		else if (ft_is_mod(format[*i]) && tab[2] <= 108 && tab[2] != 76)
			tab[2] += format[*i];
		else if (ft_isdigit(format[*i]) && format[*i] != 0)
			while (ft_isdigit(format[*i + 1]))
				(*i)++;
		else
			ft_error(2);
		if (format[*i] != 0 && !ft_what_type(format[*i]))
			(*i)++;
	}

}

void	ft_check_format(char *format)
{
	int	i;
	int tab[3];

	i = -1;
	while (format[++i] != 0)
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ft_zero(&tab[0], &tab[1], &tab[2]);
			i++;
			/*while (!ft_what_type(format[i]) && format[i] != 0)
			{
				if (ft_is_flag(format[i]) && !mod && !dot && !tab[0])
					tab[0] = 1;
				else if (format[i] == '.' && ft_isdigit(format[i + 1]) &&
						!tab[2] && !tab[1])
					tab[1] = 1;
				else if (ft_is_mod(format[i]) && tab[2] <= 108)
					tab[2] += format[i];
				else if (ft_isdigit(format[i]) && format[i] != 0)
					while (ft_isdigit(format[i + 1]))
						i++;
				else
					ft_error(2);
				if (format[i] != 0 && !ft_what_type(format[i]))
					i++;
			}*/
			ft_inner_loop(tab, format, &i);
			if (!ft_what_type(format[i]))
				ft_error(2);
		}
}
