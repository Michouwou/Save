// HEADER

int		jlst_in_jlst(j_list *great_list, j_list *to_search, int (*compare_func)(void*, void*))
{
    j_list  *tmpa;
    j_list  *tmpb;
    j_list  *tmpc;
    int     i[2];
    
    tmpa = great_list;
    i[1] = jlst_length(great_list) - jlst_length(to_search);
    while (tmpa && i[0] < i[1])
    {
        tmpb = to_search;
        if (!compare_func(tmpa->data, tmpb->data))
        {
            tmpc = tmpa;
            while (tmpc && tmpb && !compare_func(tmpc->data, tmpb->data))
            {
                tmpc = tmpc->next;
                tmpb = tmpb->next;
                i[0]++;
            }
            if (tmpb == NULL)
                return (i);
            i[0]++;
            tmpa = tmpa->next;
        }
    }
}