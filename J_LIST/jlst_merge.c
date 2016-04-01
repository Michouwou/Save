// HEADER

void    jlst_merge(j_list *first_list, j_list *second_list)
{
    int     i;
    j_list  *tmpa;
    j_list  *tmpb;
    
    tmpa = second_list;
    while (tmpa)
    {
        tmpb = first_list;
        i = 0;
        while ((tmpb = tmpb->next) && tmpb->data)
            i++;
        if (tmpb = NULL)
        {
            
        }
    }
}