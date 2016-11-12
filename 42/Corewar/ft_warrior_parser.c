/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warrior_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:15:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/11 11:16:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"

void	ft_warrior_parser(char *file_name, t_buffer **buffer, int nb_champ)
{
	int		line;
	char	**resource;
	char	*current;

	line = 0;
	ft_read_file(file_name, resource);
	ft_header_check(resource, &line);
	while (resource[line] != NULL)
	{
		current = NULL;
		if (ft_begins_with_label(resource[line]))
		{
			ft_label_check(resource[line], buffer);
			ft_check_label_instruction(resource, &line);
			current = strdup("OK");
		}
		if ((current = ft_contains_instruction(resource[line])) != NULL)
		{
			ft_instruction_validity(current);
			ft_check_arg_number(current);
			ft_check_arg_type(current);
		}
		if (current == NULL && ft_strtrim(resource[line])[0] != '#')
			ft_help("Empty or invalid line\n");
		ft_main_compiler(buffer, ft_explode_asm_line(current));
		line += 1;
	}
}
