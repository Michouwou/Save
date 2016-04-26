int		ft_is_modifier(char *str)
{
	if ((str[0] == 'l' && str[1] == 'l') || (str[0] == 'l' && str[1] != 'l') ||
		(str[0] == 'j') || (str[0] == 'z') ||
		(str[0] == 'h' && str[1] != 'h') || (str[0] == 'h' && str[1] == 'h'))
		return (1);
	return (0);
}