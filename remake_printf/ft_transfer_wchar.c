#include "libftprintf.h"

static void part_two(wchar_t c, int *oct_num, unsigned char *b)
{
	if (c < (1 << 16))
	{
		*oct_num = 3;
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*oct_num = 4;
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
}

unsigned char *ft_transfer_wchar(wchar_t c, int *oct_num)
{
	unsigned char *b_static;
	unsigned char *b;

	b_static = (unsigned char*)ft_strnew(4);
	b = b_static;
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*oct_num = 2;
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else
		part_two(c, oct_num, b);
	*b = '\0';
	return (b_static);
}