
#include "libftprintf.h"

int		ft_is_valid(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ' || c == '*' ||
			c == '.' || c == 'd' || c == 'L' || c == 'l' || c == 'j' ||
			c == 'z' || c == 'h' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'D' || c == 'U' || c == 'O' || c == 'f' || c == 'm' ||
			c == 'E' || c == 'e' || c == 'X' || c == 'x' || c == 'F' ||
			c == '%' || c == 'S' || c == 's' || c == 'c' || c == 'C' ||
			c == 'p' || c == 'b' || ft_isdigit(c))
		return (1);
	return (0);
}