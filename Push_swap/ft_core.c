/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:00:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 11:28:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_core(char **argv, int argc)
{
	t_sol	**sols;
	char	*options;
	t_stack	*alpha;
	t_stack	*beta;
	char	is_ext;

	printf("On vient d'entrer dans core\n\n");
	fflush(stdout);

	sols = (t_sol**)malloc(sizeof(t_sol*));
	*sols = ft_create_sol(0);

	printf("Creation de l'espace solution termine -> %d\n\n", (*sols)->len);
	fflush(stdout);

	options = ft_extract_options(argv, argc);

	printf("Extraction des options OK : options = %s\n\n", options);
	fflush(stdout);

	alpha = ft_fill_stack(argv, argc, options);

	printf("Remplissage de la pile alpha OK\n\n");
	fflush(stdout);
	ft_disp_stack(alpha, alpha, 'v');

	beta = ft_new_stack();

	printf("Creation de la pile beta OK, impression, adresse a et b : %p, %p\n\n", (void*)alpha, (void*)beta);
	fflush(stdout);

	alpha->name = ft_strcpy(alpha->name, "a");
	beta->name = ft_strcpy(beta->name, "b");

	printf("Nommage des piles OK\n\n");
	fflush(stdout);

	is_ext = ft_divide(alpha, beta, options, sols);

	printf("Division de la pile alpha OK, impression de l'etat des piles, alpha->len = %d\n\n", alpha->len);
	fflush(stdout);
	ft_disp_stack(alpha, beta, 'v');

	while ((!ft_circular_check(alpha) || !ft_circular_check(ft_rev_stack(beta))))
		ft_stack_sol(ft_dnext_op(alpha, beta, is_ext), sols);
	
	printf("Tri circulaire des piles OK impression :\n\n");
	fflush(stdout);
	ft_disp_stack(alpha, beta, 'v');

	ft_normalize(alpha, is_ext, sols);
	ft_normalize(beta, is_ext, sols);

	printf("Normalisation des piles terminee! sols : %s impression :\n\n", (*sols)->sols[0]);
	fflush(stdout);
	ft_disp_stack(alpha, beta, 'v');

	ft_restack(alpha, beta, sols);

	printf("Restacking done! stack_sol -> %s\n\n", (*sols)->sols[0]);
	fflush(stdout);
	ft_normalize(alpha, is_ext, sols);
	ft_disp_stack(alpha, beta, 'v');

	ft_display(options, sols);
}
