/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/22 14:32:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int main()
{
	int *p;
	int a = 38;
	char c;
	wchar_t	*chaine;
	int	n;
	int m;

	chaine = (wchar_t*)malloc(sizeof(wchar_t) * 5);
	chaine[0] = 8364;
	chaine[1] = 165;
	chaine[2] = 36;
	chaine[3] = 8356;
	chaine[4] = 0;

	p = &a;

	n = ft_printf("Int : |%d|\n", 300);
	m = printf("Int : |%d|\n", 300);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Long : |%ld|\n", 3000000000);
	m = printf("Long : |%ld|\n", 3000000000);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Long long : |%lld|\n", 30000000000);
	m = printf("Long long : |%lld|\n", 30000000000);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Intmax_t : |%jd|\n", 3000000000);
	m = printf("Intmax_t : |%jd|\n", 3000000000);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Size_t : |%zd|\n", 3000000000);
	m = printf("Size_t : |%zd|\n", 3000000000);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Unsigned (avec un negatif) : |%u|\n", -300);
	m = printf("Unsigned (avec un negatif) : |%u|\n", -300);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Chaine de caractere : |%s|\n", "Salut");
	m = printf("Chaine de caractere : |%s|\n", "Salut");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Caractere : |%c|\n", 'o');
	m = printf("Caractere : |%c|\n", 'o');
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Caractere etendu : |%C|\n", 196);
	m = printf("Caractere etendu : |%C|\n", 196);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Pointeur : |%p|\n", (void*)p);
	m = printf("Pointeur : |%p|\n", (void*)p);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (f) : |%f|\n", 5.987);
	m = printf("Double (f) : |%f|\n", 5.987);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (e) : |%e|\n", 59.87);
	m = printf("Double (e) : |%e|\n", 59.87);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (g) : |%g|\n", 59.87);
	m = printf("Double (g) : |%g|\n", 59.87);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Hexadecimal (minuscule) : |%x|\n", 255);
	m = printf("Hexadecimal (minuscule) : |%x|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Hexadecimal (majuscule) : |%X|\n", 255);
	m = printf("Hexadecimal (majuscule) : |%X|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Octal : |%o|\n", 255);
	m = printf("Octal : |%o|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Binaire : |%b|\n", 255);
	m = printf("Binaire : |%b|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Int largeur de champs 5 : |%5d|\n", 300);
	m = printf("Int largeur de champs 5 : |%5d|\n", 300);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (f) precision 4 : |%.4f|\n", 5.897645312);
	m = printf("Double (f) precision 4 : |%.4f|\n", 5.897645312);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (e) precision 4, largeur de champs 15 : |%15.4e|\n", 345.345);
	m = printf("Double (e) precision 4, largeur de champs 15 : |%15.4e|\n", 345.345);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Int, largeur de champs 5, precision 4 (*) : |%5.4d|\n", 23);
	m = printf("Int, largeur de champs 5, precision 4 (*) : |%5.4d|\n", 23);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Deux chaines de caracteres : |%s| |%s|\n", "Salut", "comment ca va?");
	m = printf("Deux chaines de caracteres : |%s| |%s|\n", "Salut", "comment ca va?");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Trois ints a la ligne, alignes a gauche :\n|%-d|\n|%-d|\n|%-d|\n", 245, 126, 90);
	m = printf("Trois ints a la ligne, alignes a gauche :\n|%-d|\n|%-d|\n|%-d|\n", 245, 126, 90);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Un int, un double (f), un caractere, avec largeur de champs (3, 4, 9 -> *) : |%*d| |%*f| |%*c|\n", 3, 23, 4, 345.0, 9, 't');
	m = printf("Un int, un double (f), un caractere, avec largeur de champs (3, 4, 9 -> *) : |%*d| |%*f| |%*c|\n", 3, 23, 4, 345.0, 9, 't');
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Sortie d'erreur : |%m|\n");
	m = printf("Sortie d'erreur : |%m|\n");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (e) arrondi, precision de 3 : |%.3e|\n", 3.999999);
	m = printf("Double (e) arrondi, precision de 3 : |%.3e|\n", 3.999999);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("8 entiers (hh) : |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd|\n", 1, 2, 3, 4, 5, 6, 7, 8);
	m = printf("8 entiers (hh) : |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd| |%hhd|\n", 1, 2, 3, 4, 5, 6, 7, 8);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Chaine simple sans arguments\n");
	m = printf("Chaine simple sans arguments\n");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Int (hh)aligne a gauche avec le signe, largeur de champs 6 et precision 4 : |%+-6.4hhd|\n", 5);
	m = printf("Int (hh)aligne a gauche avec le signe, largeur de champs 6 et precision 4 : |%+-6.4hhd|\n", 5);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Chaine de caracteres avec precision de 4 et largeur de champs de 6 : |%6.4s|\n", "Anticonstitutionnellement");
	m = printf("Chaine de caracteres avec precision de 4 et largeur de champs de 6 : |%6.4s|\n", "Anticonstitutionnellement");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Unsigned simple : |%u|\n", 678);
	m = printf("Unsigned simple : |%u|\n", 678);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Double (f) de forme alternee, precision de 0 : |%#.0f|\n", 3.45);
	m = printf("Double (f) de forme alternee, precision de 0 : |%#.0f|\n", 3.45);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Affichage du pourcent %%\n");
	m = printf("Affichage du pourcent %%\n");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Chaine de caractere alignee a droite largeur de champs de 8 : |%8s|\n", "hello");
	m = printf("Chaine de caractere alignee a droite largeur de champs de 8 : |%8s|\n", "hello");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Doubles (f puis e)signes plus : |%+e| |%+f|\n", 567.987, 67.234);
	m = printf("Doubles (f puis e)signes plus : |%+e| |%+f|\n", 567.987, 67.234);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Doubles (e puis f) zero-padding largeur de champs 12 et precision 3 : |%012.3e| |%012.3f|\n", 34.56, 34.56);
	m = printf("Doubles (e puis f) zero-padding largeur de champs 12 et precision 3 : |%012.3e| |%012.3f|\n", 34.56, 34.56);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Affichage avec le flag ' ' d'un int : |% d|\n", 67);
	m = printf("Affichage avec le flag ' ' d'un int : |% d|\n", 67);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Affichage alternatif de l'hexa (minuscule) : |%#x|\n", 255);
	m = printf("Affichage alternatif de l'hexa (minuscule) : |%#x|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Affichage alternatif de l'octal : |%#o|\n", 255);
	m = printf("Affichage alternatif de l'octal : |%#o|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Affichage alternatif du binaire : |%#b|\n", 255);
	m = printf("Affichage alternatif du binaire : |%#b|\n", 255);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Chaine de caracteres etendus : |%S|\n", chaine);
	m = printf("Chaine de caracteres etendus : |%S|\n", chaine);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");
	
	n = ft_printf("Puissance de 10 (10, 100, 1000, 10000, 100000) : |%d| |%d| |%d| |%d| |%d|\n", 10, 100, 1000, 10000, 10000);
	m = printf("Puissance de 10 (10, 100, 1000, 10000, 100000) : |%d| |%d| |%d| |%d| |%d|\n", 10, 100, 1000, 10000, 10000);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Test moulitest 18 : %s %C %d %p %x %% %S \n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	m = printf("Test moulitest 18 : %s %C %d %p %x %% %S \n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Test 0 : %c\n", 0);
	m = printf("Test 0 : %c\n", 0);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Test largeur 0 avec int, char, et string : |%d| |%c| |%s|\n", 10, 'a', "LOL");
	m = printf("Test largeur 0 avec int, char, et string : |%0d| |%0c| |%0s|\n", 10, 'a', "LOL");
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");

	n = ft_printf("Largeur de 9, precision de 4 et flag '0' sur int (26) : |%09.4d|\n", 26);
	m = printf("Largeur de 9, precision de 4 et flag '0' sur int (26) : |%09.4d|\n", 26);
	ft_printf("%d - %d --- %s\033[0;m\n\n", n, m, n - m == 0 ? "\033[1;32mOK" : "\033[1;31mFAIL");


	/*ft_printf();
	fflush(stdout);
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
