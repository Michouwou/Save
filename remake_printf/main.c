#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char *s;

	ft_printf("%3d, %s, %f, %b, %p, %s\n", 3, " salut", 0.034, 255, &p, s);
	return(0);
}
