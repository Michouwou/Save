#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include "libftprintf.h"

int main()
{
	uintmax_t num = 700;
	unsigned long num2 = 900;

	char *s = ft_strdup("Salut\n");
	printf("%s\n", s);
	s = ft_repstr(s, 0, 0, "0");
	printf("%s\n", s);
}
