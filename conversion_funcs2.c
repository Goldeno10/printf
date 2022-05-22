#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* cvt_u - handle printing of unsigned integers
* @ap: Store arguments list
* Return: number of characters printed
*/
int cvt_u(va_list ap)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	digits = base_convert(decimal_num, 10);
	num_of_char +=  _puts(digits);
	return (num_of_char);
}

/**
* cvt_o - handle printing of octal numbers
* @ap: Store arguments list
* Return: number of characters printed
*/
int cvt_o(va_list ap)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	digits = base_convert(decimal_num, 8);
	num_of_char +=  _puts(digits);
	return (num_of_char);
}


/**
* cvt_x - handle lowercase hexadecimal numbers
* @ap: Store arguments list
* Return: number of characters printed
*/
int cvt_x(va_list ap)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	digits = base_convert(decimal_num, 16);
	num_of_char +=  _puts(digits);
	return (num_of_char);
}


/**
* cvt_X - handle upercase hexadecimal numbers
* @ap: Store arguments list
* Return: number of characters printed
*/
int cvt_X(va_list ap)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	digits = base_CONVERT(decimal_num, 16);
	num_of_char +=  _puts(digits);
	return (num_of_char);
}

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
