// HEADER

void    jlst_del_list(j_list *first_node)
{
    while (first_node)
        jlst_del_node(&first_node, 1);
    free(first_node);
}