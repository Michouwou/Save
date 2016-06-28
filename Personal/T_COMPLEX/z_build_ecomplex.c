// HEADER

#include "t_complex.h"

t_complex   z_build_ecomplex(double ray, double mantis)
{
    t_complex   z;
    
    z.ray = ray;
    z.mantis = mantis;
    z.real = 0.0;
    z.imaginary = 0.0;
    z.form = 2;
    z.to_string = z_to_string(z);
    return (z);
}