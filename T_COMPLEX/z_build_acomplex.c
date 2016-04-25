// HEADER

#include "t_complex.h"

t_complex   z_build_acomplex(double real, double imaginary)
{
    t_complex   z;
    
    z.real = real;
    z.imaginary = imaginary;
    z.exp_ray = 0.0;
    z.exp_mantis = 0.0;
    z.form = 1;
    z.to_string = z_to_string(z);
    return (z);
}