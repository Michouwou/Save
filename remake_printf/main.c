#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char c;

	printf("-%d : ft_printf\n", ft_printf("%hhx, %hhx", 0, UCHAR_MAX));
	printf("-%d : printf\n", printf("%hhx, %hhx", 0, UCHAR_MAX));
	write(1, "\n", 1);
	return(0);
}
