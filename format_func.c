#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "main.h"

/**
* vfmt - format the output of a stdarg argument list
* @format: character string
* @ap: argument list
* Return: number of characters
*/
int vfmt(const char *format, va_list ap)
{
	int num = 0;
	int (*cvt)(va_list, unsigned char *, int, int);

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
			unsigned char c, flags[256];
			int width = INT_MIN, precision = INT_MIN;

			get_flag(format, flags);
			get_width(ap, format, &width);
			get_precision(ap, format, &precision);
			memset(flags, '\0', sizeof(flags));

			c = *format;
			cvt = get_cvt_func(c);
			num += (cvt ? cvt(ap, flags, width, precision) :
					_putchar(*(format - 1)) + _putchar(*(format)));
		}
		format++;
	}

	return (num);
}

/**
* get_flag - gets flag
* @fmt: pointer to the format string
* @flags: list of flags
*/
void get_flag(const char *fmt, unsigned char flags[])
{
	char *fmt_flags = "-+ 0#";

	if (fmt_flags)
	{
		unsigned char c = *fmt;

		for (; c && strchr(fmt_flags, c); c = *++fmt)
		{
			if (flags[c] < 255)
				flags[c]++;
		}
	}
}

/**
* get_width- gets width
* @ap: pointer to argument list
* @fmt: pointer to the format string
* @width: width
*/
void get_width(va_list ap, const char *fmt, int *width)
{
	if (*fmt == '*' || isdigit(*fmt))
	{
		int n;

		if (*fmt == '*')
		{
			n = va_arg(ap, int);
			fmt++;
		}
		else
		{
			for (n = 0; isdigit(*fmt); fmt++)
			{
				int d = *fmt - '0';

				n = 10 * n + d;
			}
		}
		*width = n;
	}
}

/**
* get_precision - gets precision
* @ap: pointer to argument list
* @fmt: pointer to the format string
* @prec: precision
*/
void get_precision(va_list ap, const char *fmt, int *prec)
{
	if (*fmt == '.' && (*++fmt == '*' || isdigit(*fmt)))
	{
		int n;

		if (*fmt == '*')
		{
			n = va_arg(ap, int);
			fmt++;
		}
		else
		{
			for (n = 0; isdigit(*fmt); fmt++)
			{
				int d = *fmt - '0';

				n = 10 * n + d;
			}
		}
		*prec = n;
	}
}
