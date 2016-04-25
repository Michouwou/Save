// HEADER

#include "t_complex.h"

char        *z_to_string(t_complex number)
{
    char    *representation;

    if (number.form == 1)
    {
        representation = ft_ftoa(number.real);
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), " + ");
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), ft_ftoa(number.imaginary));
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), "i");
    }
    if (number.form == 2)
    {
        representation = ft_ftoa(number.ray);
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), "e^");
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), ft_ftoa(number.mantis));
        representation = ft_repstr(representation, ft_strlen(representation), ft_strlen(representation), "i");
    }
    return (representation);
}