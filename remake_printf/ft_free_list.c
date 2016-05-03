#include "libftprintf.h"

void    ft_free_list(T_LIST **start)
{
	if ((*start) != NULL && (*start)->next != NULL)
		ft_free_list(&(*start)->next);
	free(*start);
}