#include "main.h"

/**
* _printf - produces output according to a format
* @format: is a character string
* Return: the number of characters printed
* (excluding the null byte used to end output to strings).
*/
int _printf(const char *format, ...)
{
	unsigned int i = 0, j, num_of_char = 0;
	va_list arg;
	char *string;

	if (!format)
		return (-1);

	va_start(arg, format);
	for (; format[i] != '\0'; i++)
	{
		while (format[i] != '%')
		{
			if (format[i] == '\0')
				return (num_of_char);
			num_of_char += _putchar(format[i]);
			i++;
		}

		i++;

		switch (format[i])
		{
			case 'c':
				j = va_arg(arg, int);
				num_of_char += case_c(j);
				break;

			case 's':
				string = va_arg(arg, char*);
				num_of_char += case_s(string);
				break;
			case '%':
				j = va_arg(arg, int);
				num_of_char += _putchar(37);
				break;

			case 'd':
				j = va_arg(arg, int);
				num_of_char += case_d(j);
				break;
			case 'i':
				j = va_arg(arg, int);
				num_of_char += case_i(j);
				break;


		}
	}

	va_end(arg);
	return (num_of_char);

}

