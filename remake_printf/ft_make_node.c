#include "libftprintf.h"

T_LIST	*ft_make_node(void)
{
	T_LIST	*new;

	new = (T_LIST*)malloc(sizeof(T_LIST));
	new->minus = 0;
	new->plus = 0;
	new->z_pad = 0;
	new->alternate = 0;
	new->space = 0;
	new->width = 0;
	new->accuracy = -1;
	new->is_signed = 0;
	new->type = 0;
	new->format = 0;
	new->unused = 1;
	new->mod = ft_strdup("-");
	new->incomplete = 0;
	new->oct_num = 1;
	new->next = NULL;
	return (new);
}
