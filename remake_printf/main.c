#include <stdio.h>
#include "libftprintf.h"

int main(int argc, char **argv)
{
	int p = 8;
	char c;

	printf("-%d : ft_printf\n", ft_printf("%O %u", 42L, 42L));
//	printf("-%d : ft_printf\n", ft_printf("%s%d%p%%%S%D%i%o%O%s", "bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, "hey"));
//	printf("-%d : printf\n", printf("%s%d%p%%%S%lD%i%o%O%u%lU%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
	write(1, "\n", 1);
	return(0);
}
