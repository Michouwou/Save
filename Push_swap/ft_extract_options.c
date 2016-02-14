#include "push_swap.h"

char *ft_extract_options(char **argv, int argc)
{
    int     i;
    int     j;
    char    res; 
    
    res = ft_strnew(4);
    while (**argv == '-' && argc > 1)
    {
        i = 1;
        while ((*argv)[i] != 0)
        {
            j = 0;
            if ((*argv)[i] == 'v' || (*argv)[i] == 'x' ||
                (*argv)[i] == 'c' || (*argv)[i] == 'd'))
            {
                while (j < 4 && res[j] != 0)
                    if (res[j++] == (*argv)[i])
                        ft_error();
                res[j] = (*argv)[i];
            }
            else
                ft_error();
            i++;
        }
        argv++;
    }
    return(res);
}