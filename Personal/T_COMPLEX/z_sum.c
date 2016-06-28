// HEADER

#include "t_complex.h"

t_complex   z_sum(t_complex f_term, t_complex s_term)
{
    t_complex   z;
    
    if ((f_term.form == s_term.form && f_term.form == 1) ||
        (f_term.form != s_term.form && Z_DEFAULT == 1) || Z_DEFAULT == 3)
    {
        z.real = z_to_real(f_term) + z_to_real(s_term);
        z.imaginary = z_to_imaginary(f_term) + z_to_imaginary(s_term);
    }
    if ((f_term.form == s_term.form && f_term.form == 2) ||
        (f_term.form != s_term.form && Z_DEFAULT == 2))
    {
        printf("Actually working on it, the actual representation is undefined...\n");
        Z_ERROR = "No representation known.";
        //z.ray = z_to_ray(f_term) + z_to_ray(s_term);
        //z.mantis = z_to_mantis(f_term) + z_to_mantis(s_term);
    }
    z.form = (f_term.form == s_term.form) ? f_term.form : Z_DEFAULT;
    z.to_string = z_to_string(z);
    return (z);
}