/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring_apply_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:52:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 15:57:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

wchar_t		*ft_wstring_apply_mod(T_LIST *trail, wchar_t *wstring)
{
	int i;

	i = 0;
	if (!(trail->mod) && trail->format = 's')
		while (i < ft_wstrlen(wstring))
		{
			wstring[i] = (char)(wstring[i]);
			i++;
		}
	return (wstring);
}
