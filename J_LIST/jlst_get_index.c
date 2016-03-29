// HEADER

int     jlst_get_index(j_list *first_node, void *data, int (*compare_func)(void*, void*))
{
    int     ret;
    j_list  *tmp;
    
    ret = 0;
    tmp = first_node;
    while (tmp)
    {
        ret++;
        if (!compare_func(first_node->data, data))
            break;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (-1);
    return (ret);
}