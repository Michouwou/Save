/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 14:06:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	int *p;
	int a = 38;

	p = &a;
	ft_printf("Int : |%d|\n", 300);
	ft_printf("Long : |%ld|\n", 3000000000);
	ft_printf("Long long : |%lld|\n", 30000000000);
	ft_printf("Intmax_t : |%jd|\n", 3000000000);
	ft_printf("Size_t : |%zd|\n", 3000000000);
	ft_printf("Unsigned (avec un negatif) : |%u|\n", -300);
	ft_printf("Chaine de caractere : |%s|\n", "Salut");
	ft_printf("Caractere : |%c|\n", 'o');
	ft_printf("Caractere etendu : |%C|\n", 196);
	ft_printf("Pointeur : |%p|\n", (void*)p);
	ft_printf("Double (f) : |%f|\n", 5.987);
	ft_printf("Double (e) : |%e|\n", 59.87);
	ft_printf("Double (g) : |%g|\n", 59.87);
	ft_printf("Hexadecimal (minuscule) : |%x|\n", 255);
	ft_printf("Hexadecimal (majuscule) : |%X|\n", 255);
	ft_printf("Octal : |%o|\n", 255);
	//ft_printf("Binaire : |%b|\n", 255);
	ft_printf("Int largeur de champs 5 : |%5d|\n", 300);
	ft_printf("Double (f) precision 4 : |%.4f|\n", 5.897645312);
	ft_printf("Double (e) precision 4, largeur de champs 15 : |%15.4e|\n", 345.345);
	ft_printf("Int, largeur de champs 5, precision 4 (*) : |%5.4d|\n", 23);
	ft_printf("Deux chaines de caracteres : |%s| |%s|\n", "Salut", "comment ca va?");
	ft_printf("Trois ints a la ligne, alignes a gauche :\n|%-d|\n|%-d|\n|%-d|\n", 245, 126, 90);
	ft_printf("Un int, un double (f), un caractere, avec largeur de champs (3, 4, 9 -> *) : |%*d| |%*f| |%*c|\n", 3, 23, 4, 345.0, 9, 't');
	ft_printf("Sortie d'erreur : |%m|\n");
	ft_printf("Double (e) arrondi, precision de 3 : |%.3e|\n", 3.999999);
	ft_printf("8 entiers (hh) : |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd|\n", 1, 2, 3, 4, 5, 6, 7, 8);
	ft_printf("Chaine simple sans arguments\n");
	ft_printf("Int (hh)aligne a gauche avec le signe, largeur de champs 6 et precision 4 : |%+-6.4hhd|\n", 5);
	ft_printf("Chaine de caracteres avec precision de 4 et largeur de champs de 6 : |%6.4s|\n", "Anticonstitutionnellement");
	ft_printf("Unsigned simple : |%u|\n", 678);
	ft_printf("Double (f) de forme alternee, precision de 0 : |%#.0f|\n", 3.45);
	//ft_printf("Affichage du pourcent%%\n");
	ft_printf("Chaine de caractere alignee a droite largeur de champs de 8 : |%8s|\n", "hello");
	ft_printf("Doubles (f puis e)signes plus : |%+e| |%+f|\n", 567.987, 67.234);
	ft_printf("Doubles (e puis f) zero-padding largeur de champs 12 et precision 3 : |%012.3e| |%012.3f|\n", 34.56, 34.56);
	ft_printf("Affichage avec le flag ' ' d'un int : |% d|\n", 67);
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
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();
	ft_printf();*/
	return (0);
}
