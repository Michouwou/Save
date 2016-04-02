// HEADER

int     jlst_length(j_list *first_node)
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    while (tmp)
    {
        ++i;
        tmp = tmp->next;
    }
    return (i);
}