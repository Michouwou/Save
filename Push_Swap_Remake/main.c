/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 17:35:30 by mlevieux         ###   ########.fr       */
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
    
	   	printf("Bon apparemment c'est pas l'extraction d'options, les opttions! %s\n", options);
		fflush(stdout);

	 	while (i < argc - ft_strlen(options))
            ft_add_number(&alpha, ft_atoi(argv[i++]));
		//beta = ft_create_element('b');
		
	ft_print_stack(alpha);		
	   	printf("La construction de a est apparemment correcte\n");
		fflush(stdout);
	 	ft_core(&alpha, &beta, &solution, options);

		printf("On plante dans solution\n");
		fflush(stdout);
    }
	ft_display(solution, options);
	ft_print_stack(alpha);
	printf("\n");
	ft_print_stack(beta);
	ft_add_num_sol(&solution, ft_restack(&alpha, &beta));
	
	printf("Operations = ");
	fflush(stdout);

    ft_display(solution, options);
	ft_print_stack(alpha);
}
