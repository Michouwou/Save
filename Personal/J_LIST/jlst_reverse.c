// HEADER

#include "j_list.h"

void    jlst_reverse(j_list **first_node)
{
    j_list  *tmp;
    j_list  *cursor;
    
    if (!first_node || !*first_node)
        return ;
    cursor = *first_node;
    while (cursor->next)
    {
        tmp = cursor->next;
        cursor->next = cursor->previous;
        cursor->previous = tmp;
        cursor = cursor->previous;
    }
    cursor->next = cursor->previous;
    cursor->previous = NULL;
    *first_node = cursor;
}