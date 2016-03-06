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

static void ft_increase_tab(char ***to_up, int len)
{
    char    **tmp;
    int     i;
    
    i = 0;
    tmp = *to_up;
    *to_up = (char**)malloc(sizeof(char*) * len + 6);
    while (i < len)
    {
        (*to_up^)[i] = ft_strcpy(*to_up[i], tmp[i]);
        i++;
    }
    i = 0;
    while (i < len)
        free(tmp[i++]);
    free(tmp);
}

char        **ft_get_args(char *filename, int *lines)
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
            ft_increase_tab(&result, line_num);
        if (status == -1)
            ft_block();
    }
    *lines = line_num;
    return (result);
}