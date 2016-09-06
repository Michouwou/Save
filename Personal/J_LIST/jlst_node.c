// HEADER

#include "j_list.h"

j_list  *jlst_node(void)
{
    j_list  *new;
    
    new = (j_list*)malloc(sizeof(j_list));
    new->data = NULL;
    new->list_len = 0;
    new->data_len = 0;
    new->previous = NULL;
    new->next = NULL;
    new->state = 0;
    new->alloc_ = 0;
    new->is_tree = 0;
    return (new);
}