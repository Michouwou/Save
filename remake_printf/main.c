#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char *s;

//	printf("%d : ft_printf\n", ft_printf("{%3c}", 0));
//	printf("%d : printf\n", 
	if(ft_printf("{%30S}", L"我是一只猫。") == 32)
		write(1, "-", 1);
//	write(1, "\n", 1);
	return(0);
}
