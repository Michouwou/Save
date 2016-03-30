// HEADER

int     jlst_get_size(j_list *first_node)
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    tmp = first_node;
    while (tmp)
    {
        if (tmp->state)
            i++;
        tmp = tmp->next;
    }
    return (i);
}