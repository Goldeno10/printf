#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
* _putd - prints a number with string representation
* @str: pointer to string
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of chars written
*/
int _putd(char *str, unsigned char flags[], int width, int precision)
{
	int sign, n, num_of_char = 0, len = strlen(str);

	if (str)
	{
	norm_width_and_flags(&width, &precision, flags);
	compute_sign(str, &len, &sign, flags);
	if (precision < 0)
		precision = 1;
	if (len < precision)
		n = precision;
	else if (precision == 0 && len == 1 && str[0] == '0')
		n = 0;
	else
		n = len;

	if (flags['-'])
	{
		if (sign)
			num_of_char += _putchar(sign);
	}
	else if (flags['0'])
	{
		if (sign)
			num_of_char += _putchar(sign);
		num_of_char += pad(width - n, '0');
	}
	else
	{
		num_of_char += pad(width - n, ' ');
		if (sign)
			num_of_char += _putchar(sign);
	}

	num_of_char += pad(precision - len, '0');
	for (; *str; str++)
		num_of_char += _putchar(*str);
	if (flags['-'])
		num_of_char += pad(width - n, ' ');
	}
	return (num_of_char);
}

/**
* compute_sign - Set the sign given as flags or in the string(argument)
* @str: pointer to the string
* @len: length of the string
* @sign: sign
* @flags: pointer to flags in the format string
*/
void compute_sign(char *str, int *len, int *sign, unsigned char flags[])
{
	if (str)
	{
	if (*len > 0 && (*str == '-' || *str == '+'))
	{
		*sign = *str++;
		(*len)--;
	}
	else if (flags['+'])
		*sign = '+';
	else if (flags[' '])
		*sign = ' ';
	else
		*sign = 0;
	}
}
