/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring_apply_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:52:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:08:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

wchar_t		*ft_wstring_apply_mod(T_LIST *trail, wchar_t *wstring)
{
	int i;

	i = 0;
	if (trail->mod[0] != 'l' && trail->format = 's')
		while (i < ft_wstrlen(wstring))
		{
			wstring[i] = (char)(wstring[i]);
			i++;
		}
	return (wstring);
}
