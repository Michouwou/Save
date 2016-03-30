// HEADER

void    *jlst_get_data(j_list *first_node, int index)
{
    int     i;
    j_list  *list;
    
    i = 0;
    list = first_node;
    while (i < index)
    {
        list = list->next;
        i++;
    }
    return (list->data);
}