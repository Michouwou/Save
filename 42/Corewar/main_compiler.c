/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_compiler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:02:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/11/09 19:14:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"

void	ft_main_compiler(char **champion, t_buffer **buffer)
{
	char	**iter;
	int		tmp;

	iter = champion;
	while (iter != NULL)
	{
		if (ft_is_label(*iter))
			ft_to_mem_addr(*iter, buffer);
		else if (ft_is_instruction(*iter))
		{
			ft_bufferize(buffer, ft_get_opcode(*iter), "OPC");
			ft_bufferize(buffer, ft_build_ocp(iter), "OCP");
		}
		else if (ft_is_param(*iter))
		{
			if (ft_is_index(*iter))
			{
				if (ft_addr_is_label(*iter))
					ft_get_buffer_addr(buffer, *iter);
				ft_apply_mod(buffer);
			}
			else if (ft_is_register(*iter))
				ft_check_regindex(*iter);
			ft_bufferize(buffer, ft_to_bytecode(*iter), "ARG");
		}
		iter++;
	}
	ft_dump_buffer_memory(buffer);
}
