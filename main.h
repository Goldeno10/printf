#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
* struct cvt - Struct cvt
*
* @cvt: conversion specifier
* @f: The function associated
*/
typedef struct cvt
{
		char *cvt;
		int (*f)(va_list ap);
} cvt_t;

/* get conversion function */
int (*get_cvt_func(char s))(va_list);

/**
*u_int - typedef for unsigned int
*/
typedef unsigned int u_int;

/* base convert functions */
char *base_convert(u_int, int);
char *base_CONVERT(u_int, int);

/* conversion functions */
int cvt_S(va_list ap);
int cvt_u(va_list ap);
int cvt_b(va_list ap);
int cvt_X(va_list ap);
int cvt_o(va_list ap);
int cvt_x(va_list ap);
int cvt_c(va_list ap);
int cvt_i(va_list ap);
int cvt_d(va_list ap);
int cvt_s(va_list ap);

/* write functions */
int _putchar(char c);
int _puts(char *str);

/* format functions */
int vfmt(const char *format, va_list ap);
int _printf(const char *format, ...);

#endif /* #endif MAIN_H  */
