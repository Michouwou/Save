
#include "lem_in.h"

char    **ft_read_file(int fd)
{
    char    *result;
    char    *tmp;
    char    **return_string_tab;
    
    result = ft_strnew(1);
    tmp = NULL;
    while (get_next_line(fd, &tmp) == 1)
    {
        result = ft_strjoin(result, "\n");
        result = ft_strjoin(result, tmp);
        free(tmp);
        tmp = NULL;
    }
    return_string_tab = ft_strsplit(result, '\n');
    return (return_string_tab);
}