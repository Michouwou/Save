// HEADER

int     jlst_is_sorted(j_list *first_node, int (*compare_func)(void*, void*))
{
    j_list  *tmp;
    
    tmp = first_node;
    while (tmp && tmp->next)
    {
        if (compare_func(tmp->data, tmp->next->data))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}