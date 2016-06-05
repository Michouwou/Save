// HEADER

void    jlst_nbackward(int n, j_list **first_node)
{
    while (n > 0 && (*first_node)->previous)
    {
        *first_node = (*first_node)->previous;
        --n;
    }
}