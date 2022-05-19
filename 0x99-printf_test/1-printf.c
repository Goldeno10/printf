#include "main.h"
/**
*
*
*
*
*
*/
int _printf(char *format, ...)
{
	char *traverse;
	u_int i;
	char *s;
	int len = 0, x;

	va_list vlist;
	va_start(vlist, format);

	for (traverse = format; *traverse != '\0', traverse++)
	{
		while (*traverse != '℅')
		{
			putchar(*traverse);
			traverse++;
		}
		traverse++;

		switch(*traverse)
		{
			case 'i': i = va_arg(vlist, u_int);
				case_i(i);
				x = case_i(i);
				len += x;
				break;
			case 'c': i = va_arg(vlist, u_int);
				case_c(i);
				x = case_c(i);
				len += x;
				break;
			case 's': s = va_arg(vlist, char *);
				case_s(s);
				x = case_(s);
				len += x;
				break;
			case 'd': i = va_arg(vlist, int);
				case_d(i);
				x = case_d(i);
				len += x;
		}
	}
	va_end(vlist);
	return (len);
}
