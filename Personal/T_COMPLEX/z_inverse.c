// HEADER

#include "t_complex.h"

t_complex   z_inverse(t_complex term)
{
    t_complex   z;
    
    if (!term.real && !term.imaginary)
        Z_ERROR = "Null inverse does not exist.";
    if (term.form == 1 || Z_DEFAULT == 3)
    {
        if (term.real && term.imaginary)
        {
            printf("For the moment it's going to be hard...\n");
            Z_ERROR = "No representation known.";
        }
        else if (term.real != 0)
            z.real = 1 / term.real;
        else
            z.imaginary = 1 / term.imaginary;
    }
    else if (term.form == 2)
    {
        z.ray = 1 / term.ray;
        z.mantis = (-1) * term.mantis;
    }
    z.to_string = z_to_string(z);
    return (z);
}