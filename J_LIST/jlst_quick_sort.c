// HEADER

#include "j_list.h"

void    jlst_quick_sort(j_list *list, int (*compare_func)(void*, void*))
{
    j_list  *left;
    j_list  *right;
    j_list  *pivot;
    int     is_sort;
    
    left = list;
    right = list;
    jlst_set_end(right);
    pivot = (j_list*)jlst_median(list, compare_func, 4);
    is_sort = 1;
    while (is_sort)
    {
        is_sort = 0;
        while (compare_func(right->data, pivot->data) > 0)
            right = right->previous;
        while (compare_func(left->data, pivot->data) < 0)
            left = left->next;
        if (jlst_precedes(left, right))
        {
            is_sort = 1;
            jlst_swap_nodes(right, left);
        }
    }
    right = pivot->next;
    left = pivot->previous;
    jlst_split_node(pivot, pivot, compare_func, 1);
    jlst_quick_sort(left, compare_func);
    jlst_quick_sort(right, compare_func);
    jlst_stick(3, left, pivot, right);
}