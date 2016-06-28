// HEADER

#include "t_complex.h"

t_complex   z_modulus(t_complex term)
{
    t_complex   z;
    
    if (term.form == 1)
    {
        z.real = ft_sqrt((term.real * term.real) + (term.imaginary * term.imaginary));
        z.imaginary = 0;
    }
    else
    {
        z.ray = term.ray;
        z.mantis = 1;
    }
    z.form = term.form;
    z.to_string = z_to_string(z);
    return (z);
}