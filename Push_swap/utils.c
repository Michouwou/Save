/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:54:04 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 13:57:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *stra, char *strb)
{
	int		i;
	char	*ret;

	i = ft_strlen(stra);
	ret = ft_strnew(i + ft_strlen(strb));
	ft_strcpy(ret, stra);
	ft_strcat(ret + i, strb);
	free(stra);
	return (ret);
}
