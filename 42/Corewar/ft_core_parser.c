/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/09 21:06:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"

void	ft_parse_main_args(char **args, int nb_args, t_vm **machine)
{
	int i;
	int nb_champ;

	i = 0;
	nb_champ = -1;
	if (nb_args < 2)
		ft_help("You have to provide at least one argument.\n");
	while (i < nb_args)
	{
		if (!ft_strcmp(args[i], "-dump") && !(*machine)->dump)
			ft_get_dump_option(args[++i], machine);
		else if (!ft_strcmp(args[i], "-n") && nb_champ == -1)
			nb_champ = ft_atoi(args[++i]);
		else if (ft_parse_match("*.cor", args[i]))
		{
			ft_load_champion(args[i], machine, nb_champ);
			nb_champ = -1;
		}
		else if (!ft_strcmp(args[i], "-n") && nb_champ != -1)
			ft_help("A single champion can't have several numbers\n");
		else
			ft_help("Arguments not well formatted\n");
		i += 1;
	}
	ft_check_machine_state(machine);
}


