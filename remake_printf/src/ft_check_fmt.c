int		ft_check_fmt(char const *fmt)
{
	int		i;

	i = 0;
	while (ft_is_valid(fmt[i]) && !ft_is_format(fmt[i]) && fmt[i])
		++i;
	if (!ft_is_valid(fmt[i]))
		return (1); // Code incomplet
	else if (ft_is_format(fmt[i]) || !fmt[i])
		return (2); // Code ca a l'air bon
	else
		return (0); //Code y a un serieux probleme quelque part!
}