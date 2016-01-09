/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:27:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/06 17:33:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char 	*ft_base(long num, int base);

char	*ft_address(void *pointer)
{
	unsigned		i;
	char			*res;
	char			*tmp;

	i = (unsigned)pointer;
	res = (char*)malloc(sizeof(char)*200);
	tmp = res;
	strcpy(res, "0x");
	res += 2;
	strcpy(res, ft_base(i, 16));
	return(tmp);
}
