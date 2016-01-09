/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:51:16 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/08 15:20:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

wchar_t	*ft_char(char *flaglen, char **str, int beg, wchar_t c)
{
	wchar_t	*res;
	int		i;

	i = beg;
	while (!ft_what_type(*str[i]))
		i++;
	if (*str[i] == 'c' && c > 127)
		ft_error();
	res = ft_wstrnew(2);
	res[0] = c;
	ft_complete_char(&res, flaglen);
	return (res);
}
