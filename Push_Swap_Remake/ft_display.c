
#include "push_swap.h"

static void	ft_color(char *color, char *to_print)
{
	write(1, "\033[0;", 4);
	write(1, color, ft_strlen(color));
	write(1, "m", 1);
	write(1, to_print, ft_strlen(to_print));
	write(1, "\033[0;m", 5);
}

static void ft_display_unit(char *operation)
{
    if (!ft_strcmp(operation, "sa") || !ft_strcmp(operation, "sb"))
        ft_color("31", operation);
    if (!ft_strcmp(operation, "rra") || !ft_strcmp(operation, "rrb"))
        ft_color("32", operation);
    if (!ft_strcmp(operation, "ra") || !ft_strcmp(operation, "rb"))
        ft_color("33", operation);
    if (!ft_strcmp(operation, "rrr"))
        ft_color("34", operation);
    if (!ft_strcmp(operation, "pa"))
        ft_color("35", operation);
    if (!ft_strcmp(operation, "pb"))
        ft_color("36", operation);
    if (!ft_strcmp(operation, "rr"))
        ft_color("37", operation);
    if (!ft_strcmp(operation, "ss"))
        ft_color("0", operation);
}

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
    
        i++;
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