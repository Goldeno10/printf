#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* cvt_c - handle character printing
* @ap: stores argument list
* Return: number of characters printed
*/

int cvt_c(va_list ap)
{
	int num_of_char = _putchar((unsigned char)va_arg(ap, int));

	return (num_of_char);
}

/**
* cvt_s - prints string
* @ap: stores argument list
* Return: number of characters printed
*/

int cvt_s(va_list ap)
{
	unsigned int num_of_char;
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(null)";

	num_of_char = _puts(str);

	return (num_of_char);
}
