void	ft_get_accuracy(char *location, int *counter, T_LIST *trail)
{
	int	i;
	
	i = *counter + 1;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->accuracy = ft_atoi(ft_strsub(location, i, *counter - i));
	(*counter) -= 1;
}