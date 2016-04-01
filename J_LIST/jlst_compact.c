// HEADER

void    jlst_compact(j_list *first_node)
{
    j_list *tmpa;
    j_list *tmpb;
    j_list *element;
    
    element = first_node;
    while (element)
    {
        tmpa = element;
        while (tmpa->previous && !tmpa->previous->data)
        {
            tmpb = tmpa->previous;
            tmpa->next = tmpb;
            tmpa->previous = tmpb->previous;
            tmpb->previous = tmpa;
            tmpb->next = tmpa->next;
        }
        element = element->next;
    }
}