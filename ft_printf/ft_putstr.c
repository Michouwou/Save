#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_error()
{
	write(1, "lol", 3);
	exit (0);
}

int	ft_putstr(wchar_t *str, char format)
{
	int i;

	i = -1;
	if (format == 's' || format == 'S')
		while (str[++i] != 0)
			write(1, &str[i], 1);
	else if (format == 'c' || format == 'C')
	{
		write(1, str, 1);
		return (1);
	}
	else
		ft_error();
	return (i);
}

int main()
{
	wchar_t c;
	wchar_t *str;
	wchar_t *mdr = L"lol";

	c = 'a';
	str = (wchar_t*)malloc(sizeof(wchar_t) * 10);
	str = (wchar_t*)mdr;
	//ft_putstr(&c, 'c');
	printf("%s\n", (char*)mdr);
	//ft_putstr(str, 's');
	//ft_putstr(&c, 'r');
	return (0);
}
