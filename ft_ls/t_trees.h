/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_trees.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:58:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct      s_tree
{
    void            *data;
    int             size;
    struct s_tree   *left;
    struct s_tree   *right;
}                   t_tree;

t_tree      *ft_create_node();
void        ft_insert_sort(int (*compare_func)(), void *data);
