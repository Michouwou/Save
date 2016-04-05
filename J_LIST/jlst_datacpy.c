// HEADER

void        *jlst_datacpy(j_list *node)
{
    unsigned char   *data;
    unsigned char   *copy;
    int             i;
    
    data = (unsigned char)node->data;
    copy = (unsigned char*)malloc(sizeof(unsigned char) * (node->data_len + 1));
    i = 0;
    while (i < node->data_len)
    {
        copy = node->data[i];
        i++;
    }
    return ((void)copy);
}