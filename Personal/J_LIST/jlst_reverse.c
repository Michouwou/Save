// HEADER

#include "j_list.h"

void    jlst_reverse(j_list **first_node)
{
    j_list  *tmpa;
    j_list  *tmpb;
    j_list  *cursor;
    
    if (!first_node || !*first_node)
        return ;
    cursor = *first_node;
    tmpb = cursor->next->next;
    while (tmpb)
    {
        tmpa = cursor->next;
        tmpb = tmpa->next;
        cursor->next = cursor->previous;
        cursor->previous = tmpa;
        cursor = tmpb->previous;
    }
    *first_node = cursor;
}