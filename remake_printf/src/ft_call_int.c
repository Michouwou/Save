static void	ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int		ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = ft_base(number, trail->format);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}