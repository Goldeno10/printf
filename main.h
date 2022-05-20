#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
*u_int - typedef for unsigned int
*/
typedef unsigned int u_int;

char *base_convert(u_int, int);
char *base_CONVERT(u_int, int);
int _printf(const char *format, ...);

int case_S(char *str);

int case_u(u_int);
int case_b(u_int);
int case_X(u_int);
int case_o(u_int i);
int case_x(u_int i);
int case_c(int i);
int case_i(int i);
int case_d(int i);
int case_s(char *s);

int _putchar(char c);
int _puts(char *str);
int print_str(char *str);

#endif /* #endif MAIN_H  */
