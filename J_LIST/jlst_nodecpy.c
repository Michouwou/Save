// HEADER

j_list      *jlst_nodecpy(j_list *to_copy)
{
    j_list  *new_node;
    
    new_node = (j_list*)malloc(sizeof(j_list));
    new_node->data = jlst_datacpy(to_copy);
    new_node->data_len = to_copy->data_len;
    new_node->next = to_copy->next;
    new_node->previous = to_copy->previous;
    new_node->state = to_copy->state;
    return (new_node);
}