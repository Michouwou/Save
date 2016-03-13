
#include "lem_in.h"

void    ft_print_move(t_ant *ant)
{
    ft_printf("L%d-%s", ant->number, ant->actual->name);
}