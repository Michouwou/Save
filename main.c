/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 11:36:16 by mlevieux         ###   ########.fr       */
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
    
    alpha = NULL;
    beta = NULL;
    i = 0;
    if (argc < 2)
        ft_stop();
    else
    {
        options = ft_extract_options(argv);
    
	   	printf("Bon apparemment c'est pas l'extraction d'options, les opttions! %s\n", options);
		fflush(stdout);

	 	while (i < argc - ft_strlen(options))
            ft_add_number(&alpha, ft_atoi(argv[i++]));
		beta = ft_create_element('b');
		
	ft_print_stack(alpha);		
	   	printf("La construction de a est apparemment correcte\n");
		fflush(stdout);

	 	solution = ft_core(alpha, beta, options);

		printf("On plante dans solution\n");
		fflush(stdout);
    }

    ft_display(solution, options);
}
