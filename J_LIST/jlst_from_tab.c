//HEADER

j_list      *jlst_from_tab(void *tab, int size, int length)
{
    void    *tmp;
    j_list  *list;
    j_list  *tmp_list;
    
    tmp = tab;
    list = jlst_new(length);
    tmp_list = list;
    while (list)
    {
        list->data = tmp;
        list->data_len = sizeof(*list->data);
        list->state = 1;
        tab += size;
        list = list->next;
    }
    return (tmp_list);
}