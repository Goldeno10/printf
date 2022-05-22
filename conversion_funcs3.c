#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* cvt_S - prints custom conversion specifier
* @ap: stores argument list
* Return: number of characters printed
*/

int cvt_S(va_list ap)
{
	char *str = va_arg(ap, char *);
	int num_of_char = 0;
	char *hex;

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			hex = base_CONVERT(*str, 16);
			num_of_char += _puts("\\x");
			if (!hex[1])
			{
				num_of_char += _putchar('0');
			}
			num_of_char += _puts(hex);
		}
		else
		{
			num_of_char += _putchar(*str);
		}
	}

	return (num_of_char);
}
