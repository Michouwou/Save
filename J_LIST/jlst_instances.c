// HEADER

int     jlst_instances(j_list *first_node, void *data, int (*compare_func)(void*, void*))
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    tmp = first_node;
    while (tmp)
    {
        if (!compare_func(tmp->data, data))
            i++;
        tmp = tmp->next;
    }
    return (i);
}