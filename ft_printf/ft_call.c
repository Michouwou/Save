/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:35:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 12:24:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_call_int(intmax_t nb, wchar_t **str, int beg, int end)
{
	ft_repstr(str, beg, end, ft_int(ft_length(ft_flags(str, beg), str, beg),
				str, beg, nb));
}

void	ft_call_pointer(unsigned nb, wchar_t **str, int beg, int end)
{
	ft_repstr(str, beg, end, ft_address(ft_length(ft_flags(str, beg), str, beg),
				str, beg, nb));
}

void	ft_call_char(wchar_t c, wchar_t **str, int beg, int end)
{
	ft_repstr(str, beg, end, ft_char(ft_length(ft_flags(str, beg), str, beg),
				str, beg, c));
}

void	ft_call_string(wchar_t *wstr, wchar_t **str, int beg, int end)
{
	ft_repstr(str, beg, end, ft_string(ft_length(ft_flags(str, beg), str, beg),
				str, beg, wstr));
}
