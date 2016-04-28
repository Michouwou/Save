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
				else if (fmt[i] == '*' && tmp->width == -1)
					tmp->width = -10; // Penser a changer get_accuracy pour le wildcard
				else if (ft_isdigit(fmt[i]))
				{
					tmp->unused = (tmp->width == -10) ? tmp->unused + 1 : tmp->unused;
					ft_get_width(fmt, &i, tmp);
				}
				else if (fmt[i] == '.')
					ft_get_accuracy(fmt, &i, tmp);
				else if (ft_is_modifier(&(fmt[i])))
					ft_get_greatest_modifier(fmt, &i, tmp);
				else if (fmt[i] == '*')
					tmp->unused++;
				i++;
			}
			if (ft_is_format(fmt[i]))
				ft_get_fmt(tmp, fmt[i]);
			else
				tmp->incomplete = 1;
			tmp->end_index = i;
		}
		i++;
	}
	return (args->next);
}
