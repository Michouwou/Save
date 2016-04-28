#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char c;

	printf("-%d : ft_printf\n", ft_printf("% X|%+X", 42, 42));
	printf("-%d : printf\n", printf("% X|%+X", 42, 42));
	write(1, "\n", 1);
	return(0);
}
