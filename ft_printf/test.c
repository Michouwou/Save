
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	wchar_t d;

	c = 'y';
	d = (wchar_t)c;
	printf("%d, %d", c, d);
	return(0);
}
