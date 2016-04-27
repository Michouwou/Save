#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
	uintmax_t num = 700;
	unsigned long num2 = 900;
	
	printf("%ju\n", num);
	num = (uintmax_t)num2;
	printf("%lu, %ju\n", num2, num);
}
