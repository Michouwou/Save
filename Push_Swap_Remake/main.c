/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:16:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 14:46:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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
        while (i < argc - ft_strlen(options))
            ft_add_number(alpha, ft_atoi(argv[i]), 'a');
        solution = ft_core(alpha, beta, options);
    }
    ft_display(solution, options);
}
