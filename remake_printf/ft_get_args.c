#include "libftprintf.h"

T_LIST	*ft_get_args(char *fmt, int *buffer)
{
	T_LIST	*args;
	T_LIST	*tmp;
	int		i;
	int		j;

	args = ft_make_node();
	tmp = args;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			tmp->next = ft_make_node();
			tmp = tmp->next;
			tmp->buffer = buffer;
			tmp->start_index = i++;
			while (ft_is_valid(fmt[i]) && !ft_is_format(fmt[i]))
			{
				if (fmt[i] == '-')
					tmp->minus = 1;
				else if (fmt[i] == '+')
					tmp->plus = 1;
				else if (fmt[i] == '0')
					tmp->z_pad = 1;
				else if (fmt[i] == '#')
					tmp->alternate = 1;
				else if (fmt[i] == ' ')
					tmp->space = 1;
				else if (fmt[i] == '*' && tmp->width != -10)
					tmp->width = -10;
				else if (fmt[i] == '*' && tmp->width == -10)
					tmp->accuracy = -10;
				else if (ft_isdigit(fmt[i]))
					ft_get_width(fmt, &i, tmp);
				else if (fmt[i] == '.')
					ft_get_accuracy(fmt, &i, tmp);
				else if (ft_is_modifier(&(fmt[i])))
					ft_get_greatest_modifier(fmt, &i, tmp);
				i++;
			}
			if (ft_is_format(fmt[i]))
				ft_get_fmt(tmp, fmt[i]);
			else if (!fmt[i])
				tmp->incomplete = 1;
			else
				ft_wildcard(tmp, fmt, &i);
			printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %s, %s, %c, %c, %d, %d\n", tmp->start_index, tmp->end_index, tmp->minus, tmp->plus, tmp->alternate, tmp->z_pad, tmp->space, tmp->width, tmp->accuracy, tmp->mod, tmp->wildcard, tmp->format, tmp->type, tmp->incomplete, tmp->is_signed);fflush(stdout);
			tmp->end_index = i;
		}
		i++;
	}
	return (args->next);
}
