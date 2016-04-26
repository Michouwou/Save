char    *ft_set_length(T_LIST *trail, char *result, int *state_value)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (result[++j] != 0)
		if (ft_isdigit(result[j]))
			i++;
	i = trail->accuracy - i;
	j = 0;
	while (!ft_isdigit(result[j]) && result[j] != 0)
		j++;
	if (trail->type == 'd' && i > 0)
		result = ft_repstr(result, j, j, ft_strset(ft_strnew(i), i, '0'));
	else if (trail->type == 'S' || trail->type == 's')
		result[trail->accuracy] = 0;
	return (result);
}