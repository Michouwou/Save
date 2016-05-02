/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:28:26 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 15:41:40 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "libftprintf.h"

int main()
{
	int my_printf;
	int real_printf;

	printf("Usage :\n- ft_printf return\n- printf return\n- Difference de retour = ft_printf return value - printf return value\n\n");

	my_printf = ft_printf("Double (f) : |%f|\n", 5.987);
	real_printf = printf("Double (f) : |%f|\n", 5.987);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Double (e) : |%e|\n", 59.87);
	real_printf = printf("Double (e) : |%e|\n", 59.87);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Binaire : |%b|\n", 255);
	real_printf = printf("Binaire : |%b|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Double (f) precision 4 : |%.4f|\n", 5.897645312);
	real_printf = printf("Double (f) precision 4 : |%.4f|\n", 5.897645312);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Double (e) precision 4, largeur de champs 15 : |%15.4e|\n", 345.345);
	real_printf = printf("Double (e) precision 4, largeur de champs 15 : |%15.4e|\n", 345.345);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Un int, un double (f), un caractere, avec largeur de champs (3, 4, 9 -> *) : |%*d| |%*f| |%*c|\n", 3, 23, 4, 345.0, 9, 't');
	real_printf = printf("Un int, un double (f), un caractere, avec largeur de champs (3, 4, 9 -> *) : |%*d| |%*f| |%*c|\n", 3, 23, 4, 345.0, 9, 't');
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Sortie d'erreur : |%m|\n");
	real_printf = printf("Sortie d'erreur : |%m|\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Double (e) arrondi, precision de 3 : |%.3e|\n", 3.999999);
	real_printf = printf("Double (e) arrondi, precision de 3 : |%.3e|\n", 3.999999);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Double (f) de forme alternee, precision de 0 : |%#.0f|\n", 3.45);
	real_printf = printf("Double (f) de forme alternee, precision de 0 : |%#.0f|\n", 3.45);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Doubles (f puis e)signes plus : |%+e| |%+f|\n", 567.987, 67.234);
	real_printf = printf("Doubles (f puis e)signes plus : |%+e| |%+f|\n", 567.987, 67.234);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Doubles (e puis f) zero-padding largeur de champs 12 et precision 3 : |%012.3e| |%012.3f|\n", 34.56, 34.56);
	real_printf = printf("Doubles (e puis f) zero-padding largeur de champs 12 et precision 3 : |%012.3e| |%012.3f|\n", 34.56, 34.56);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Affichage alternatif du binaire : |%#b|\n", 255);
	real_printf = printf("Affichage alternatif du binaire : |%#b|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
}
