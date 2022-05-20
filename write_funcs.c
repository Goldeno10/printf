#include <unistd.h>
#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
		return (write(1, &c, 1));
}


/**
* _puts - prints a string
* @str: pointer to string
* Return: number of chars written
*/
int _puts(char *str)
{
	int num_of_char = 0;

	while (*str != '\0')
		num_of_char += _putchar(*str++);

	return (num_of_char);
}
