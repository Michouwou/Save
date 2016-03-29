//HEADER

j_list      *jlst_from_tab(void *tab, int size, int length)
{
    void    *tmp;
    j_list  *list;
    
    tmp = tab;
    list = jlst_new(length);
    while (list->next)
    {
        list->data = tmp;
        list->data_len = sizeof(*list->data);
        list->state = 1;
        tab += size;
        list = list->next;
    }
    list->data = tmp;
    list->data_len = sizeof(*list->data);
    list->state = 1;
    while (list->previous)
        list = list->previous;
    return (list);
}