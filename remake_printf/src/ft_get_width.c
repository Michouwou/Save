void	ft_get_width(char *location, int *counter, T_LIST *trail)
{
	int	i;

	i = *counter;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->width = ft_atoi(ft_strsub(location, i, *counter - i));
	(*counter) -= 1;
}