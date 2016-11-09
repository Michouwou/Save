/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/09 19:14:31 by mlevieux         ###   ########.fr       */
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
			ft_warrior_parser(args[i], machine, nb_champ);
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

void	ft_warrior_parser(char *file_name, t_buffer **buffer, int nb_champ)
{
	int		line;
	char	**resource;
	char	*label_temp;
	char	*current;

	line = 0;
	ft_read_file(file_name, resource);
	ft_header_check(resource, &line);
	while (resource[line] != NULL)
	{
		if (ft_begins_with_label(resource[line]))
		{
			ft_label_check(resource[line], &label_temp);
			ft_check_label_instruction(resource, &line);
		}
		if ((current = ft_contains_instruction(resource[line])) != NULL)
		{
			ft_instruction_validity(current);
			ft_check_arg_number(current);
			ft_check_arg_type(current);
		}
		else
			ft_help("Empty or invalid line\n");
		ft__main_compiler(buffer, current, label_temp);
		line += 1;
	}
}
