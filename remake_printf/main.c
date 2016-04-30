#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char c;

	printf("-%d : ft_printf\n", ft_printf("{%03c}", 0));
	printf("-%d : printf\n", printf("{%03c}", 0));
	write(1, "\n", 1);
	return(0);
}
