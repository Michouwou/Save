
#include "push_swap.h"

void    ft_display(t_sol *solution, char *options)
{
    int i;
    
    i = 0;
    while (i < solution->len - 1)
    {
        if (options[0] == 'C' || options[1] == 'C' ||
        options[2] == 'C' || options[3] == 'C' ||
        options[4] == 'C')
        {
            ft_display_unit(solution->operations[i]);
            ft_printf(", ");
        }
        else
            ft_printf("%s, ", solution->operations[i]);
    }
    if (options[0] == 'c' || options[1] == 'c' ||
        options[2] == 'c' || options[3] == 'c' ||
        options[4] == 'c' || options[0] == 'C' ||
        options[1] == 'C' || options[2] == 'C' ||
        options[3] == 'C' || options[4] == 'C')
        ft_display_unit(solution->operations[i]);
    else
        ft_printf("%s", solution->operations);
    ft_printf("\n");
}