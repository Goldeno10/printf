#include "main.h"

/**
*case_c - handle character printing
*@i:chracter ASCII code
*Return: An Int
*/

int case_c(int i)
{
	int len = 0;

	len = _putchar(i);

	return (len);
}

/**
*case_c - handle base 10 digit printing
*@j:Digit to print
*Return: An Integer
*/

int case_d(int j)
{
	char *digits;
	int len = 0;

	if (j < 0)
	{
		j = -j;
		_putchar('-');
	}
	digits = base_convert(j, 10);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}

/**
*case_i - handle integer printing
*@j:Integer to print
*Return: An Int
*/

int case_i(int j)
{
	char *digits;
	int len = 0;

	if (j < 0)
	{
		j = -j;
		_putchar('-');
	}
	digits = base_convert(j, 10);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}

/**
* case_s - prints string
* @str: pointer to string
* Return: number of characters printed
*/

int case_s(char *str)
{
	int i = 0, num_of_char = 0;
	char *np;

	if (str)
	{
		while (str[i] != '\0')
		{
			num_of_char += _putchar(str[i]);
			i++;
		}
	}
	else
	{
		np = "(nil)";
		num_of_char += write(1, np, 5);
	}
	return (num_of_char);
}

/**
*case_x - Hexadeximal case
*@i: input data
*Return: An int
*/

int case_x(u_int i)
{
	char *digits;
	int len = 0;

	digits = base_convert(i, 16);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}

/**
*case_o - Octal base case
*@i: input data
*@Return: An Int
*/

int case_o(u_int i)
{
	char *digits;
	int len = 0;

	digits = base_convert(i, 8);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}


/**
*case_X - Hexadeximal case
*@i: input data
*Return: An int
*/

int case_X(u_int i)
{
	char *digits;
	int len = 0;

	digits = base_CONVERT(i, 16);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}

/**
*case_b - Hexadeximal case
*@i: input data
*Return: An int
*/

int case_b(u_int i)
{
	char *digits;
	int len = 0;

	digits = base_convert(i, 2);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}

/**
*case_u - handle unsigned ints
*@j:Digit to print
*Return: An Integer
*/

int case_u(u_int j)
{
	char *digits;
	int len = 0;

	digits = base_convert(j, 10);
	while (digits[len] != '\0')
	{
		_putchar(digits[len]);
		len++;
	}
	return (len);
}
