#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *lol;

	lol = (char*)malloc(sizeof(char) * 6);
	lol = "ioioio";
	printf("%8.4c", 'O');
}
