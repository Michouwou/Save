
#include "lem_in.h"

void    ft_link_rooms(t_room **rooms, char **args, int len)
{
    t_room  *tmp_room_one;
    t_room  *tmp_room_two;
    int     cursors[2];
    char    **tmp_link;

    cursors[0] = 0;
    while (cursors[0] < len)
    {
        cursors[1] = 0;
        tmp_room_one = NULL;
        tmp_room_two = NULL;
        tmp_link = ft_strsplit(args[cursors[0]], '-');
        while (!rooms[cursors[1]]->name && !(tmp_room_one && tmp_room_two))
        {
            if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[0]))
                tmp_room_one = rooms[cursors[1]];
            if (!ft_strcmp(rooms[cursors[1]]->name, tmp_link[1]))
                tmp_room_two = rooms[cursors[1]];
            cursors[1]++;
        }
        ft_link_room(tmp_room_one, tmp_room_two);
        free(tmp_link[0]);
        free(tmp_link[1]);
        cursors[0]++;
    }
}