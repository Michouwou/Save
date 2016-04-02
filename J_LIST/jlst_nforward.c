// HEADER

void    jlst_nforward(int n, j_list **first_node)
{
    while (n < 0 && (*first_node)->next)
    {
        *first_node = (*first_node)->next;
        --n;
    }
}