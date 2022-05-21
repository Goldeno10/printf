#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* vfmt - format the output of a stdarg argument list
* @format: character string
* @ap: argument list
* Return: number of characters
*/
int vfmt(const char *format, va_list ap)
{
	unsigned int c;
	int num = 0;
	int (*cvt)(va_list);

	if (!format)
		return (-1);

	if (format[0] == '%' && format[1] == '\0')
					return (-1);

	while (*format)
	{
		if (*format != '%' || *++format == '%')
		{
			num += _putchar(*format);
		}
		else
		{
			c = *format;
			cvt = get_cvt_func(c);
			num += (cvt ? cvt(ap) : _putchar(*(format - 1)) + _putchar(*(format)));
		}
		format++;
	}

	return (num);
}
