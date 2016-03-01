
#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include "libftprintf.h"
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct  s_stack
{
    int     *numbers;
    int     len;
    int     med;
    void    *bool;
}               t_stack;

