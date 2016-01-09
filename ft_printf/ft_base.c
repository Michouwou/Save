#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

char *ft_base(long num, int base)
{
	char	*final;
	int		k;
	long	i;
	char	alpha[17];

	i = 1;
	k = 0;
	strcpy(alpha, "0123456789abcdef");
	bzero(final = (char*)malloc(sizeof(char) * 200), 200);
	while ((i * base) < num)
			i = i * base;
	write(1, "trois\n", 6);
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
		write(1, "youpi\n", 6);
	}
	final[k] = 0;
	write(1, "quatre\n", 7);
	return (final);
}
