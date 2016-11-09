/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:52:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/07 20:09:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"

void	ft_help(char *error_message)
{
	ft_putstr(error_message);
	ft_putstr("Usage : ./corewar [-dump nbr_cycles] [[-n number]"
				"champion1.cor] ...\n"
				"- -dump will just dump the memory to the screen every"
				" nbr_cycles cycles so that you can debugg or only follow"
				" the evolution of the machine.\n"
				"- You can specify the number you want any champion"
				" to have with the -n option, if 'number' is not available"
				" then the machine will give the following champion the"
				" closest number it can.\n"
				"- You have to provide at least one champion for the"
				" machine to work fine, files which name does not end"
				" with '.cor' will be considered errors.\n");
	exit(0);
}
