
#include "lem_in.h"

t_room  **ft_get_rooms(char ***args, int *number_of_rooms)
{
    int     i;
    t_room  **result;
    char    **tmp;
    int     flags[2];
    
    i = 0;
    while (!ft_strchr(args[i], '-'))
        i++;
    result = (t_room**)malloc(sizeof(t_room*) * (i + 1));
    i = 0;
    while (!ft_strchr(args[i], '-'))
    {
        tmp = ft_strsplit(args[i], ' ');
        if (!ft_strcmp(tmp[0], "##start") || !ft_strcmp(tmp[0], "##end"))
            flags[!ft_strcmp(tmp[0], "##start") ? 0 : 1] = 1;
        else if (!ft_strchr(tmp[0], '#'))
        {
            result[*number_of_rooms] = ft_create_room(tmp[0], flags[1], flags[0]);
            flags[0] = 0;
            flags[1] = 0;
        }
        free(tmp);
        i++;
        *number_of_rooms += 1;
    }
    result[*number_of_rooms] = ft_create_room(NULL, 0, 0);
    args += i;
    return (result);
}