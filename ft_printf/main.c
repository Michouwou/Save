/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 12:29:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	char *str;
	T_LIST *list;
	T_LIST *start;

	str = malloc(500);
	str = "mdr %#o, lol mdr %.76je yo tout va %#05.8Ls, %-899.72hhi\0";
	ft_check_format(str);
	list = ft_find_form(str);
	start = list;
	while (list != NULL)
	{
		printf("start : %d, end : %d, accuracy : %d, width : %d, type : %c, format : %c, flag : %c, mod : %s\n", list->start_index, list->end_index, list->accuracy, list->width, list->type, list->format, list->flag, list->mod);
		list = list->next;
	}
	ft_free_list(&start);
	return (0);
}
