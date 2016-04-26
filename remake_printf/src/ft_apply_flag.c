char *ft_apply_flag(char *result, T_LIST *trail, int *state_value)
{
	char t;

	t = trail->format;
	if ((trail->type == 'd' || trail->type == 'f') && (trail->plus ||
				trail->space || result[0] == '-'))
	{
		if (trail->plus && ft_isdigit(result[0]) && (t != 'o' && t != 'O' &&
					t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, "+");
		else if (trail->space && ft_isdigit(result[0]) && (t != 'o'
				&& t != 'O' && t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, " ");
	}
	if (trail->alternate)
		result = ft_alternate(result, trail);
	return (result);
}