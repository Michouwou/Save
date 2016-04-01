// HEADER

void    jlst_del_data(j_list **first_node, void *data, int (*compare_func)(void*, void*))
{
    int     i;
    j_list  *tmp;
    
    i = 1;
    tmp = *first_node;
    while (tmp)
    {
        if (!compare_func(tmp->data, data))
            jlst_del_node(first_node, i);
        tmp = tmp->next;
        i++;
    }
}