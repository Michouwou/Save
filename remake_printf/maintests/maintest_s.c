/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:54:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 16:22:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
	setlocale(LC_ALL, "");

	int		my_printf;
	int		real_printf;

	printf("Usage : \n- Out ft_printf\n- Out printf\n- Return value my_printf - return value real_printf\n\n");
	fflush(stdout);

	my_printf = ft_printf("String : |%s|\n", "Salut trololol j'ecris de la merde juste pour tester mon putin de programme");
	real_printf = printf("String : |%s|\n", "Salut");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Extended string : |%ls|\n", L"毛泽东/毛澤東");
	real_printf = printf("Extended string : |%ls|\n", L"毛泽东/毛澤東");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (12) : |%.12s|\n", "Bonjour voyageur");
	real_printf = printf("Precision (12) : |%.12s|\n", "Bonjour voyageur");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision bonus (*) : |%.*s|\n", 12, "Cette chaine est coupee");
	real_printf = printf("Precision bonus (*) : |%.*s|\n", 12, "Cette chaine est coupee");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (25) : |%25s|\n", "Il n'y aura ici que 25 caracteres");
	real_printf = printf("Largeur (25) : |%25s|\n", "Il n'y aura ici que 25 caracteres");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (18) et precision (12) : |%18.12s|\n", "Encore une chaine inutile");
	real_printf = printf("Largeur (18) et precision (12) : |%18.12s|\n", "Encore une chaine inutile");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-40s|\n", "Il y a trop d'espace!");
	real_printf = printf("Flag - : |%-40s|\n", "Il y a trop d'espace!");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - avec largeur (20) et precision (10) : |%-20.10s|\n", "Et la pas assez");
	real_printf = printf("Flag - avec largeur (20) et precision (10) : |%-20.10s|\n", "Et la pas assez");
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
