#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* _printf - produces output according to a format
* @format: is a character string
* Return: the number of characters printed
* (excluding the null byte used to end output to strings).
*/
int _printf(const char *format, ...)
{
	unsigned int num_of_char = 0;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);
	num_of_char += vfmt(format, ap);

	va_end(ap);
	return (num_of_char);
}
