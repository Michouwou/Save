#include "libftprintf.h"

static void     ft_isneg(intmax_t *num, int *k, char *final)
{
	if (*num < 0)
	{
		*num = -(*num);
		*k = 1;
		final[0] = '-';
	}
}

static void     ft_make_base(int *base)
{
	if (*base == 'o' || *base == 'O')
		*base = 8;
	if(*base == 'x' || *base == 'X')
		*base = 16;
	if (*base == 'b')
		*base = 2;
	if (*base == 'd' || *base == 'D' || *base == 'i')
		*base = 10;
}

char            *ft_base(intmax_t num, int base)
{
	char            *final;
	int             k;
	intmax_t        i;
	char            alpha[17];

	ft_make_base(&base);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_bzero(final = (char*)malloc(sizeof(char) * 200), 200);
	ft_isneg(&num, &k, final);
	while ((i * base) <= num)
		i = i * base;
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
	}
	final[k] = 0;
	return (final);
}