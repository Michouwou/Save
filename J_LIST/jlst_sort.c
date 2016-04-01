// HEADER

void    jlst_sort(j_list **first_node, int (*compare_func)(void*, void*))
{
    int     min;
    j_list  *tmp;
    j_list  *min_e;
    j_list  *new;
    
    new = jlst_new(1);
    while (*first_node)
    {
        tmp = *first_node;
        min_e = tmp;
        while (tmp)
        {
            if (compare_func(tmp->data, min_e->data) < 0)
                min_e = tmp;
            tmp = tmp->next;
        }
        if (min_e->previous == NULL && (*first_node)->next)
            *first_node = (*first_node)->next;
        jlst_push_back(&new, min_e->data);
        jlst_del_data(first_node, min_e->data);
    }
    jlst_del_list(first_node);
    *first_node = new;
}