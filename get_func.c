#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
* get_cvt_func - selects the correct function to perform the
* conversion
* @s: pointer to string constant
* Return: return a pointer to the function that takes variable
* argument list and return int
 */
int (*get_cvt_func(char s))(va_list)
{
		cvt_t cvts[] = {
			{"c", cvt_c},
			{"s", cvt_s},
			{"d", cvt_d},
			{"i", cvt_i},
			{"b", cvt_b},
			{NULL, NULL}
		};

		int i;

		i = 0;
		while (i < 5)
		{
			if (*(cvts[i].cvt) == s)
				return (cvts[i].f);
			i++;
		}

		return (cvts[i].f);
}
