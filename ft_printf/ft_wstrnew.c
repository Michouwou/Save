/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:33:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/22 11:26:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstring;
	int		i;

	printf("\t\t\tPas a l'entree de new tout de meme...,size vaut = %zd\n", size);
	NOW
	i = 0;
	wstring = (wchar_t*)malloc(sizeof(wchar_t) * size + 1);
	if (wstring == NULL)
		return (NULL);
	printf("\t\t\tEt la ca s'affiche?\n");
	NOW
	while (i < (int)size + 1)
	{
		wstring[i] = 0;
		i++;
	}
	printf("\t\t\tNi wstrnew\n");
	NOW
	return (wstring);
}
