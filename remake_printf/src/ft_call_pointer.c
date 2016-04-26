int		ft_call_pointer(unsigned pointer, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = pointer ? ft_base(pointer, 16) : ft_strdup("0");
	result = ft_repstr(result, 0, 0, "0x");
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}