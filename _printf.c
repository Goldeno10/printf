#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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
	const	char *traverse;

	if (!format)
		return (-1);

	va_start(arg, format);
	for (traverse = format; traverse[i] != '\0'; i++)
	{
		while (traverse[i] != '%')
		{
			if (traverse[i] == '\0')
				return (num_of_char);
			num_of_char += _putchar(traverse[i]);
			i++;
		}
		i++;

		switch (traverse[i])
		{
			case 'c':
				j = va_arg(arg, int);
				_putchar(j);
				break;

			case 's':
				string = va_arg(arg, char*);
				num_of_char += print_str(string);
		}
	}

	va_end(arg);
	return (num_of_char);

}


/**
* print_str - prints string
* @str: pointer to string
* Return: number of characters printed
*/
int print_str(char *str)
{

	int num_of_char = 0;
	char *np;

	if (str)
	{
		while (*str)
		{
			num_of_char += _putchar(*str);
			str++;
		}
	}
	else
	{
			np = "(nil)";
			num_of_char += write(1, np, 5);
	}
	return (num_of_char);
}
