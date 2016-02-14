#include "push_swap.h"

int     ft_check_args(int *prev_stack, int len, long nb, char *options)
{
    int flag;
    int i;
    
    i = -1;
    flag = 0;
    if (nb > 2147483647 || nb < -2147483648)
        ft_error();
    while (++i < len)
        if ((long)prev_stack[i] == nb)
            flag = 1;
    if (flag && (options[0] == 'd' || options[1] == 'd'
        || options[2] == 'd' || options[3] == 'd'))
        return (1);
    else if (flag)
        ft_error();
    else
        return(1);
}