#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
/**
* pad - fill spaces with character given as input
* @n: number of times to print the character
* @c: character
* Return: number of times c is printed
*/
int pad(int n, char c)
{
	int len = 0;

	while (n-- > 0)
	{
		_putchar(c);
		len++;
	}
	return (len);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned
*/
int _putchar(char c)
{
	static char buf[1024];
	int i = (int)c;

	if (buf[i])
	{
		write(1, &buf[i], 1);
	}
	else
	{
		buf[i] = c;
		write(1, &buf[i], 1);
	}
	return (1);
}

/**
* _puts - prints a string
* @str: pointer to string
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of chars written
*/
int _puts(char *str, unsigned char flags[], int width, int precision)
{
	int len = strlen(str), num_of_char = 0;
	char *hex;

	if (str)
	{
	norm_width_and_flags(&width, &precision, flags);
	if (precision >= 0 && precision < len)
		len = precision;

	if (!flags['-'])
	{
		num_of_char += pad(width - len, ' ');
	}

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			hex = base_CONVERT(*str, 16);
			num_of_char += _puts("\\x", flags, width, precision);
			if (!hex[1])
			{
				num_of_char += _putchar('0');
			}
			num_of_char += _puts(hex, flags, width, precision);
		}
		else
		{
			num_of_char += _putchar(*str);
		}
	}
	if (flags['-'])
		num_of_char += pad(width - len, ' ');
	}

	return (num_of_char);
}

/**
* norm_width_and_flags - normalize width and flags
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
*/
void norm_width_and_flags(int *width, int *precision, unsigned char flags[])
{
	if (*width == INT_MIN)
		*width = 0;
	if (*width < 0)
	{
		flags['-'] = 1;
		*width = -(*width);
	}

	if (*precision >= 0)
		flags['0'] = 0;
}
