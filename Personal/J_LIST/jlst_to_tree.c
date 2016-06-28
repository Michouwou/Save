// HEADER

#include "j_list.h"

void	    jlst_to_tree(j_list **first_node, int (*compare_func)(void*, void*), char is_avl)
{
    j_list  *tmp;
    j_list  *platform;
    
    if (first_node && *first_node && !(*first_node)->is_tree)
    {
        tmp = jlst_duplicate(*first_node);
        tmp = jlst_quick_sort(tmp, compare_func);
        jlst_to_tree_treatment(&tmp);
        platform = *first_node;
        *first_node = tmp;
        jlst_del_list(platform);
    }
}

static void	jlst_to_tree_treatment(j_list *first_node, char is_avl)
{
    j_list  *median_node;
    j_list  *left_list;
    j_list  *right_list;
    
    median_node = jlst_median(first_node, compare_func, 4);
    median_node->is_tree = 1;
    median_node->is_avl = is_avl;
    if (median_node->previous)
    {
        median_node->previous->next = NULL;
        left_list = first_node;
        median_node->previous = jlst_to_tree_treatment(left_list, is_avl);
    }
    if (median_node->next)
    {
        median_node->next->previous = NULL;
        right_list = median_node->next;
        median_node->next = jlst_to_tree_treatment(right_list, is_avl);
    }
    return (median_node);
}