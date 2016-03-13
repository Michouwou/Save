
#include "lem_in.h"

void    ft_core(t_room **rooms, t_ant **ants)
{
    t_path  **paths;
    int     status;
    
    paths = ft_find_paths(rooms);
    status = 1;
    while (status)
        status = ft_iterate(ants, paths);
    if (!ft_free_everything(paths, rooms, ants))
        ft_block("Erreur de libération de la mémoire...");
}