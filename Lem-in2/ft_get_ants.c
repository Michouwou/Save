
#include "lem_in.h"

t_ant   **ft_get_ants(char ***args, int *number_of_ants)
{
    t_ant   **ants;
    int     tmp;
    
    tmp = ft_atoi((*args)[0]);
    if (tmp == 0)
        ft_block("No ants, then no one to cross the lem");
    ants = (t_ant**)malloc(sizeof(t_ant*) * tmp);
    *number_of_ants = tmp;
    tmp = 0;
    while (tmp < *number_of_ants)
    {
        ants[tmp] = ft_create_ant(tmp + 1);
        tmp++;
    }
    (*args)++;
    return (ants);
}