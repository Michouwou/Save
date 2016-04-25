//HEADER

#ifndef _T_COMPLEX_H
# define _T_COMPLEX_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "libft.h"

unsigned char   Z_DEFAULT = 1;
char            Z_ERROR[100] = "There is no error or it is unknown."

/**
 * For any operation on complex numbers, the default representation will be
 * represented by the global variable Z_DEFAULT :
 * - (1) : Default will be algebric form
 * - (2) : Default will be exponential form
 * - (3) : Default will be trigonometric form with sinus and cosinus
 * If any error occurs for any function, a 'null' complex be returned (for
 * functions supposed to return a complex) or equivalent (for other return
 * value) to 0, and the global variable Z_ERROR will be set to the correct
 * value.
 **/



typedef struct	s_complex
{
    long double     real;
    long double     imaginary;
    long double     exp_ray;
    long double     exp_mantis;
    char            *to_string;
    unsigned char   form;
}               t_complex;

t_complex   z_build_acomplex(double real, double imaginary);
/**
 * Returns a complex of the algebric form
 **/
t_complex   z_build_ecomplex(double ray, double mantis);
/**
 * Returns a complex of the exponential form
 **/
t_complex   z_sum(t_complex f_term, t_complex s_term);
/**
 * Returns a complex that is the result of the sum of f_term and s_term
 **/
t_complex   z_product(t_complex f_term, t_complex s_term);
/**
 * Returns a complex that is the result of the product of f_term and s_term
 **/
t_complex   z_inverse(t_complex term);
/**
 * Returns a complex that is the inverse of the term 'term'
 **/
char        *z_to_string(t_complex number);
/**
 * Returns a string that represents the complex 'number'
 **/
t_complex   z_conjugate(t_complex term);
/**
 * Returns a complex that is the conjugate of the complex 'term'
 **/
t_complex   z_modulus(t_complex term);
/**
 * Returns a complex that represents the modulus of the term 'term'
 **/
t_point     z_affix(t_complex point);
/**
 * Returns a structure of type 't_point' representing the affix of the complex
 * 'point'
 **/
void        z_print(t_complex number, unsigned char mode);
/**
 * Prints the complex 'number' according to the field 'mode' :
 * - 1 : Prints number in the algebric form
 * - 2 : Prints number in the exponential form
 * - 0 : Prints number in the form it is already represented
 **/
int         t_are_equal(t_complex f_term, t_complex s_term);
/**
 * Returns 0 if f_term and s_term are different, 1 if they're equal
 **/
t_complex   z_middle(t_complex f_point, t_complex s_point);
/**
 * Returns a complex that represents the middle of the affix of the complex
 * f_point and the affix of the complex s_point
 **/
t_complex   z_barycentre(int args_num, t_complex *complexes);
/**
 * Returns a complex that represents the barycentre of the affix of the array
 * 'complexes'
 **/