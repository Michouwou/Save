void	ft_wildcard(T_LIST *trail, char *fmt, int *i)
{
	trail->wildcard = ft_strset(ft_strnew(1), 1, fmt[*i]);
}