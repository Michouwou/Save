/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 16:08:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *options;
    int     i;
    t_stack *alpha;
    t_stack *beta;
    t_sol   *solution;
	t_sol	*tmp_sol;
    
    alpha = NULL;
    beta = NULL;
    i = 1;
    if (argc < 2)
        ft_stop();
    else
    {
        options = ft_extract_options(argv);
	 	while (i < argc - ft_strlen(options))
            ft_add_number(&alpha, ft_atoi(argv[i++]));
		//beta = ft_create_element('b');
		
	ft_print_stack(alpha);		
	 	ft_core(&alpha, &beta, &solution, options);
    }
	ft_add_num_sol(&solution, ft_restack(&alpha, &beta));

	ft_ator(&solution);	
    ft_display(solution, options);
	ft_print_stack(alpha);
}
