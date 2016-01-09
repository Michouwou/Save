/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:48:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 17:25:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#define NOW fflush(stdout);

int	ft_what_type(char f);
int ft_is_flag(char f);
void utf8();
wchar_t *ft_conv_wchar(char *s);
wchar_t *ft_wstrsub(wchar_t *ws, int start, size_t size);
wchar_t *ft_wstrnew(size_t len);
int ft_watoi(const wchar_t *ws);
wchar_t *ft_wstrdup(wchar_t const *wstring);
size_t ft_wstrlen(wchar_t const *wstring);

void	ft_error()
{
	printf("ERROR\n");
	NOW
	exit(0);
}

char	ft_what_mod(wchar_t *s)
{
	if (s[0] == 'h' && s[1] != 'h')
		return ('h');
	else if (s[0] == 'h' && s[1] == 'h')
		return ('H');
	else if (s[0] == 'l' && s[1] != 'l')
		return ('l');
	else if (s[0] == 'l' && s[1] == 'l')
		return ('L');
	else
		return (0);
}
char	*ft_flags(wchar_t **string, int beg)
{
	int		i;
	char	*res;
	int		j;

	i = beg;
	res = ft_strnew(5);
	printf("ok s = %S\n", *string);
	printf("flag? : %d\n", ft_is_flag((char)(*string)[i + 1]));
	NOW
	if (ft_is_flag((char)(*string)[i + 1]))
	{
		res[0] = (char)(*string)[i + 1];
		i++;
	}
	i++;
	j = i;
	while (ft_isdigit((char)(*string)[i]))
		i++;
	printf ("Ici i = %d\n", i);
	res[1] = (i > j) ? ft_watoi(ft_wstrsub(*string, j, i - j)) : 32;
	printf("%d\n", ft_watoi(ft_wstrsub(*string, j, i - j)));
	printf ("Et res[1] = %c\n", res[1]);
	NOW
	if ((*string)[i] == '.')
	{
		j = i;
		i++;
		while (ft_isdigit((*string)[i]))
			i++;
	}
	printf("i = %d, j = %d\n", i, j);
	NOW
	res[2] = (i > j) ? ft_watoi(ft_wstrsub(*string, j, i - j)) : 32;
	printf("Soit res[2] : %d\n", res[2]);
	NOW
	while (ft_what_mod(*(string + i)))
		i++;
	res[3] = (i > j) ? ft_what_mod(ft_wstrsub(*string, j, i - j)) : 32;
	printf("%S, %d\n", ft_wstrsub((*string), j, i), i - j);
	printf("%C\n", (*string)[i]);
	NOW
	if (!ft_what_type((*string)[i]))
		ft_error();
	printf("Passe ft_error(), res[3] = %c!\n", res[3]);
	res[4] = '\0';
	return (res);
}

int main()
{
	utf8();
	char *s = "%08.4d";
	char *s2 = "%.19d";
	char *s3 = "Lol %d";
	char *s4 = "%#64.9hhd mdr";
	wchar_t *ws = ft_conv_wchar(s);
	wchar_t *ws2 = ft_conv_wchar(s2);
	wchar_t *ws3 = ft_conv_wchar(s3);
	wchar_t *ws4 = ft_conv_wchar(s4);
	printf("%s\n", ft_flags(&ws, 0));
	printf("%s\n", ft_flags(&ws2, 0));
	printf("%s\n", ft_flags(&ws3, 4));
	printf("%s\n", ft_flags(&ws4, 0));
}
