/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 15:40:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "libftprintf.h"

int main()
{
	int *p;
	int a = 38;
	wchar_t	*chaine;
	int	my_printf;
	int real_printf;

	setlocale(LC_ALL, "");

	chaine = (wchar_t*)malloc(sizeof(wchar_t) * 5);
	chaine[0] = 8364;
	chaine[1] = 165;
	chaine[2] = 36;
	chaine[3] = 8356;
	chaine[4] = 0;

	p = &a;

	printf("Usage :\n- ft_printf return\n- printf return\n- Difference de retour = ft_printf return value - printf return value\n\n");

	my_printf = ft_printf("Int : |%d|\n", 300);
	real_printf = printf("Int : |%d|\n", 300);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Long : |%ld|\n", 3000000000);
	real_printf = printf("Long : |%ld|\n", 3000000000);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Long long : |%lld|\n", (long long)30000000000);
	real_printf = printf("Long long : |%lld|\n", (long long)30000000000);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Intmax_t : |%jd|\n", 3000000000);
	real_printf = printf("Intmax_t : |%jd|\n", 3000000000);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	my_printf = ft_printf("Size_t : |%zd|\n", 3000000000);
	real_printf = printf("Size_t : |%zd|\n", 3000000000);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Unsigned (avec un negatif) : |%u|\n", -300);
	real_printf = printf("Unsigned (avec un negatif) : |%u|\n", -300);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Chaine de caractere : |%s|\n", "Salut");
	real_printf = printf("Chaine de caractere : |%s|\n", "Salut");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Caractere : |%c|\n", 'o');
	real_printf = printf("Caractere : |%c|\n", 'o');
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Caractere etendu : |%C|\n", 196);
	real_printf = printf("Caractere etendu : |%C|\n", 196);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Pointeur : |%p|\n", (void*)p);
	real_printf = printf("Pointeur : |%p|\n", (void*)p);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	/*	
	my_printf = ft_printf("Double (g) : |%g|\n", 59.87);
	real_printf = printf("Double (g) : |%g|\n", 59.87);
	printf("Difference de retour : %d\n", real_printf - my_printf);
	fflush(stdout);
	*/

	my_printf = ft_printf("Hexadecimal (minuscule) : |%x|\n", 255);
	real_printf = printf("Hexadecimal (minuscule) : |%x|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Hexadecimal (majuscule) : |%X|\n", 255);
	real_printf = printf("Hexadecimal (majuscule) : |%X|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Octal : |%o|\n", 255);
	real_printf = printf("Octal : |%o|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Int largeur de champs 5 : |%5d|\n", 300);
	real_printf = printf("Int largeur de champs 5 : |%5d|\n", 300);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Int, largeur de champs 5, precision 4 (*) : |%5.4d|\n", 23);
	real_printf = printf("Int, largeur de champs 5, precision 4 (*) : |%5.4d|\n", 23);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Deux chaines de caracteres : |%s| |%s|\n", "Salut", "comment ca va?");
	real_printf = printf("Deux chaines de caracteres : |%s| |%s|\n", "Salut", "comment ca va?");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Trois ints a la ligne, alignes a gauche :\n|%-d|\n|%-d|\n|%-d|\n", 245, 126, 90);
	real_printf = printf("Trois ints a la ligne, alignes a gauche :\n|%-d|\n|%-d|\n|%-d|\n", 245, 126, 90);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("8 entiers (hh) : |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd|\n", (char)1, (char)2, (char)3, (char)4, (char)5, (char)6, (char)7, (char)8);
	real_printf = printf("8 entiers (hh) : |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd|\n", (char)1, (char)2, (char)3, (char)4, (char)5, (char)6, (char)7, (char)8);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Chaine simple sans arguments\n");
	real_printf = printf("Chaine simple sans arguments\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Int (hh)aligne a gauche avec le signe, largeur de champs 6 et precision 4 : |%+-6.4hhd|\n", (char)5);
	real_printf = printf("Int (hh)aligne a gauche avec le signe, largeur de champs 6 et precision 4 : |%+-6.4hhd|\n", (char)5);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Chaine de caracteres avec precision de 4 et largeur de champs de 6 : |%6.4s|\n", "Anticonstitutionnellement");
	real_printf = printf("Chaine de caracteres avec precision de 4 et largeur de champs de 6 : |%6.4s|\n", "Anticonstitutionnellement");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Unsigned simple : |%u|\n", 678);
	real_printf = printf("Unsigned simple : |%u|\n", 678);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Affichage du pourcent %%\n");
	real_printf = printf("Affichage du pourcent %%\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Chaine de caractere alignee a droite largeur de champs de 8 : |%8s|\n", "hello");
	real_printf = printf("Chaine de caractere alignee a droite largeur de champs de 8 : |%8s|\n", "hello");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Affichage avec le flag ' ' d'un int : |% d|\n", 67);
	real_printf = printf("Affichage avec le flag ' ' d'un int : |% d|\n", 67);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Affichage alternatif de l'hexa (minuscule) : |%#x|\n", 255);
	real_printf = printf("Affichage alternatif de l'hexa (minuscule) : |%#x|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Affichage alternatif de l'octal : |%#o|\n", 255);
	real_printf = printf("Affichage alternatif de l'octal : |%#o|\n", 255);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Chaine de caracteres etendus : |%S|\n", chaine);
	real_printf = printf("Chaine de caracteres etendus : |%S|\n", chaine);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);
	
	my_printf = ft_printf("Puissance de 10 (10, 100, 1000, 10000, 100000) : |%d| |%d| |%d| |%d| |%d|\n", 10, 100, 1000, 10000, 100000);
	real_printf = printf("Puissance de 10 (10, 100, 1000, 10000, 100000) : |%d| |%d| |%d| |%d| |%d|\n", 10, 100, 1000, 10000, 100000);
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
	fflush(stdout);

	/*ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();*/
	return (0);
}
