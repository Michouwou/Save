#include "libftprintf.h"

void	ft_get_greatest_modifier(char *fmt, int *counter, T_LIST *trail)
{
	if (fmt[*counter] == 'j')
		trail->mod = ft_strdup("j");
	else if (fmt[*counter] == 'z')
		trail->mod = ft_strdup("z");
	else if (fmt[*counter] == 'l' && fmt[*counter + 1] == 'l')
		trail->mod = ft_strdup("ll");
	else if (fmt[*counter] == 'l' && fmt[*counter + 1] != 'l' &&
		ft_strcmp(trail->mod, "ll"))
		trail->mod = ft_strdup("l");
	else if (fmt[*counter] == 'h' && fmt[*counter + 1] != 'h' &&
		trail->mod[0] != 'l')
		trail->mod = ft_strdup("h");
	else if (fmt[*counter] == 'h' && fmt[*counter + 1] == 'h' && !trail->mod)
		trail->mod = ft_strdup("hh");
}