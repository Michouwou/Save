// HEADER

#include "j_list.h"

void    jlst_swap_nodes(j_list *node_one, j_list *node_two)
{
    j_list  *tmp;
    
    tmp = node_one->next;
    node_one->next = node_two->next;
    node_two->next = tmp;
    tmp = node_one->previous;
    node_one->previous = node_two->previous;
    node_two->previous = tmp;
}