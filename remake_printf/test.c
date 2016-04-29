#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <locale.h>

int main()
{
	uintmax_t num = 700;
	unsigned long num2 = 900;

	setlocale(LC_ALL, "");
	printf("%d\n", printf("{%*c}", -15, 0));
}
