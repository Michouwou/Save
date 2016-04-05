// HEADER

void    jlst_sed(j_list *first_node)
{
    j_list      *tmpa;
    j_list      *tmpb;
    
    tmpa = first_node;
    while (tmpa)
    {
        tmpb = tmpa->next;
        while (tmpb && !tmpb->data)
            tmpb = tmpb->next;
        if (tmpb == NULL)
        {
            tmpb = tmpa->next;
            tmpa->next = NULL;
            tmpb->previous = NULL;
            jlst_del_list(tmpb);
            return;
        }
        else
            tmpa = tmpa->next;
    }
}