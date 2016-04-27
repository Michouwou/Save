#include "libftprintf.h"

wchar_t     *ft_conv_wchar(char *str)
{
	wchar_t *res;
	int     i;

	i = -1;
	if (!str)
		return (NULL);
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen(str) + 1);
	while (str[++i] != 0)
		res[i] = (unsigned char)str[i];
	res[i] = 0;
	return (res);
}