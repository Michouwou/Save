/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:31:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:32:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_sort(j_list **first_node, int (*compare_func)(void*, void*), int code)
{
    j_list  *tmp;
    j_list  *min_e;
    j_list  *new;
    
    new = NULL;
    printf("On y est\n");
    while (*first_node)
    {
        printf("boucle principale : %f\n", *(double*)(*first_node)->data);
        tmp = *first_node;
        min_e = tmp;
        while (tmp)
        {
            if (compare_func(tmp->data, min_e->data) > 0)
                min_e = tmp;
            tmp = tmp->next;
        }
        printf("Avant le push_front : %f\n", *(double*)min_e->data);
        jlst_push_front(&new, malloc(min_e->data_len), min_e->data_len);
        printf("Apres le push_front\n");
        ft_memcpy(new->data, min_e->data, min_e->data_len);
        printf("Apres memcpy, jlst_get_index : %d\n", jlst_get_index(*first_node, min_e->data, compare_func));
        jlst_del_node(first_node, jlst_get_index(*first_node, min_e->data, compare_func), code);
        tmp = new;
        while (tmp)
        {
            printf("\tData : %f\n", *(double*)tmp->data);
            tmp = tmp->next;
        }
    }
    *first_node = new;
    printf("On sort\n");
}
