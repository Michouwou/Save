// HEADER

#include "t_complex.h"

t_complex   z_conjugate(t_complex term)
{
    t_complex   z;
    
    if (term.form == 1)
    {
        z.real = (-1) * term.real;
        z.imaginary = term.imaginary;
    }
    else
    {
        z.mantis = (-1) * term.mantis;
        z.ray = term.ray;
    }
    z.to_string = z_to_string(z);
    z.form = term.form;
}