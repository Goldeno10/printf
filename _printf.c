#include "main.h"

/**
* _printf - produces output according to a format
* @format: is a character string
* Return: the number of characters printed
* (excluding the null byte used to end output to strings).
*/
int _printf(const char *format, ...)
{
	u_int j, num_of_char = 0;
	va_list arg;
	char *string;

	if (!format)
		return (-1);

	va_start(arg, format);

	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	while(*format)
	{
		if (*format != '%' || *++format == '%')
		{
				num_of_char += _putchar(*format);
				format++;
		}
		else
		{
			switch (*format)
			{
				case 'c':
					j = va_arg(arg, int);
					num_of_char += case_c(j);
					break;

				case 's':
					string = va_arg(arg, char*);
					num_of_char += case_s(string);
					break;

				case 'd':
					j = va_arg(arg, int);
					num_of_char += case_d(j);
					break;

				case 'i':
					j = va_arg(arg, int);
					num_of_char += case_i(j);
					break;

				case 'o':
					j = va_arg(arg, u_int);
					num_of_char += case_o(j);
					break;

				case 'x':
					j = va_arg(arg, u_int);
					num_of_char += case_x(j);
					break;
				case 'X':
					j = va_arg(arg, u_int);
					num_of_char += case_X(j);
					break;

				case 'b':
					j = va_arg(arg, u_int);
					num_of_char += case_b(j);
					break;

				case 'u':
					j = va_arg(arg, u_int);
					num_of_char += case_u(j);
					break;

				case 'S':
					string = va_arg(arg, char *);
					num_of_char += case_S(string);
					break;
			}
			format++;
		}
	}

	va_end(arg);
	return (num_of_char);

}
