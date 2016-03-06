/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char    **ft_get_args(char *filename, int *lines)
{
    int     fd;
    int     status;
    char    **result;
    int     line_num;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_block();
    status = 1;
    line_num = 0;
    result = (char**)malloc(sizeof(char*) * 6);
    while (status)
    {
        status = get_next_line(fd, &(result[line_num]));
        ++line_num;
        if (!(line_num % 6))
            ft_increase_tab(&result);
        if (status == -1)
            ft_block();
    }
    *lines = line_num;
    return (result);
}