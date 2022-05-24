#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* cvt_S- prints string.
* Non printable characters (0 < ASCII value < 32 or >= 127) are
* printed this way: \x, followed by the ASCII code value in hexadecimal
* (upper case - always 2 characters)
* @ap: stores argument list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/
int cvt_S(va_list ap, unsigned char flags[], int width, int precision)
{
	int num_of_char = 0;
	char *str = va_arg(ap, char *);

	if (!str)
		num_of_char += puts("(null)");
	else
	{
		num_of_char += _puts(str, flags, width, precision);
	}
	return (num_of_char);
}


/**
* cvt_p - prints pointer as hexadecimal
* @ap: stores argument list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/
int cvt_p(va_list ap, unsigned char flags[], int width, int precision)
{
	unsigned long decimal_num = (unsigned long)va_arg(ap, void *);
	int num_of_char = 0;
	char *digits;

	digits = base_convert(decimal_num, 16);
	num_of_char += _putd(digits, flags, width, precision);
	return (num_of_char);
}
