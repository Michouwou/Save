/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:01:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/08 15:11:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

wchar_t	*ft_string(char *flaglen, char **str, int beg, wchar_t *wstr)
{
	wchar_t	*res;
	int		i;

	i = beg;
	while (!ft_what_type(*str[i]))
		i++;
	if (*str[i] == 's')
	{
		i = -1;
		while (wstr[++i] != '\0')
			if (wstr[i] > 127)
				ft_error();
	}
	res = ft_wstrnew(ft_wstrlen(wstr));
	res = ft_wstrcpy(res, wstr);
	ft_complete_string(&res, flaglen);
	return (res);
}
