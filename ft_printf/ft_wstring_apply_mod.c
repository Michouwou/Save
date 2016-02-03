/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring_apply_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:27:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/03 12:28:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t *ft_wstring_apply_mod(T_LIST *trail, wchar_t *wstring)
{
    int i;

    i = 0;
    if (trail->mod[0] != 'l' && trail->format == 's')
        while (wstring[i])
        {
            wstring[i] = (char)(wstring[i]);
            i++;
        }
    return (wstring);
}
