void    ft_move_index(T_LIST **trail, int padding)
{
	T_LIST *tmp;

	tmp = *trail;
	while (tmp != NULL)
	{
		tmp->start_index += padding;
		tmp->end_index += padding;
		tmp = tmp->next;
	}
}