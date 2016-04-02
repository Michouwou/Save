// HEADER

void    jlst_resize(j_list **first_node)
{
    int     i;
    j_list  *new_list;
    j_list  *tmpa;
    j_list  *tmpb;
    
    new_list = jlst_new(2 * jlst_length(*first_node));
    i = 0;
    tmpa = *first_node;
    tmpb = new_list;
    while (tmpa)
    {
        if (!(i % 2))
        {
            ft_memcpy(tmpb->data, tmpa->data);
            tmpb->data_len = tmpa->data_len;
            tmpb->state = 1;
            tmpa = tmpa->next;
        }
        i++;
        tmpb = tmpb->next;
    }
    jlst_del_list(*first_node);
    *first_node = new_list;
}