// HEADER

void    jlst_del_node(j_list **first_node, int index)
{
    int     i;
    j_list  *tmp;
    
    i = 1;
    tmp = *first_node;
    while (i < index)
    {
        i++;
        tmp = tmp->next;
    }
    if (tmp->previous)
        tmp->previous->next = tmp->next;
    if (tmp->next)
        tmp->next->previous = tmp->previous;
    if (tmp->data)
        free(tmp->data);
    if (!tmp->previous)
        *first_node = (*first_node)->next;
    free(tmp);
}