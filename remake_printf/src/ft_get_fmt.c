void	ft_get_fmt(T_LIST *trail, char fmt)
{
	if (fmt == 'd' || fmt == 'i' || fmt == 'o' || fmt == 'u' || fmt == 'D' ||
		fmt == 'O' || fmt == 'x' || fmt == 'X' || fmt == 'U' || fmt == 'b')
		trail->type = 'd';
	else if (fmt == 'e' || fmt == 'E' || fmt == 'f' || fmt == 'F')
		trail->type = 'f';
	else if (fmt == 'c' || fmt == 'C')
		trail->type = 'c';
	else
		trail->type = fmt;
	trail->format = fmt;
}