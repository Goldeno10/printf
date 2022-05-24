#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* cvt_c - handle character printing
* @ap: stores argument list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/

int cvt_c(va_list ap, unsigned char flags[], int width, int precision)
{
	int num_of_char = 0;
	(void)flags;
	(void)width;
	(void)precision;

	num_of_char += _putchar((unsigned char)va_arg(ap, int));

	return (num_of_char);
}

/**
* cvt_s - prints string
* @ap: stores argument list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/

int cvt_s(va_list ap, unsigned char flags[], int width, int precision)
{
	unsigned int num_of_char;
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(null)";

	num_of_char = _puts(str, flags, width, precision);

	return (num_of_char);
}


/**
* cvt_d - handle base 10 digit printing
* @ap:Stoe arguments list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/

int cvt_d(va_list ap, unsigned char flags[], int width, int precision)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	if (decimal_num < 0)
	{
		decimal_num = -decimal_num;
		num_of_char += _putchar('-');
	}
	digits = base_convert(decimal_num, 10);
	num_of_char +=  _putd(digits, flags, width, precision);
	return (num_of_char);
}

/**
* cvt_i - handle integers printing
* @ap: Store arguments list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/

int cvt_i(va_list ap, unsigned char flags[], int width, int precision)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	if (decimal_num < 0)
	{
		decimal_num = -decimal_num;
		num_of_char += _putchar('-');
	}
	digits = base_convert(decimal_num, 10);
	num_of_char += _putd(digits, flags, width, precision);
	return (num_of_char);
}

/**
* cvt_b - handle binary printing
* @ap: Store arguments list
* @flags: pointer to flags in the format string
* @width: width given in the format string
* @precision: precision given in the format string
* Return: number of characters printed
*/

int cvt_b(va_list ap, unsigned char flags[], int width, int precision)
{
	int num_of_char = 0;
	int decimal_num = va_arg(ap, int);
	char *digits;

	digits = base_convert(decimal_num, 2);
	num_of_char +=  _putd(digits, flags, width, precision);
	return (num_of_char);
}

