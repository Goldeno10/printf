#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


/* Prinf Function */
int _printf(const char *format, ...);

/**
* struct cvt - Struct cvt
*
* @cvt: conversion specifier
* @f: The function associated
*/
typedef struct cvt
{
		char *cvt;
		int (*f)(va_list ap, unsigned char flags[], int width, int precision);
} cvt_t;

/**
* get_cvt_func - selects the correct function to perform the
* conversion
* @flags: list of flags
* @width: width
* @precision: precision
* Return: return a pointer to the function that takes variable
* argument list and return int
*/
int (*get_cvt_func(char s))(va_list ap,
		unsigned char flags[], int width, int precision);

/**
*u_int - typedef for unsigned int
*/
typedef unsigned int u_int;

/* base convert functions */
char *base_convert(u_int, int);
char *base_CONVERT(u_int, int);

/* conversion functions */
int cvt_S(va_list ap, unsigned char flags[], int width, int precision);
int cvt_u(va_list ap, unsigned char flags[], int width, int precision);
int cvt_b(va_list ap, unsigned char flags[], int width, int precision);
int cvt_X(va_list ap, unsigned char flags[], int width, int precision);
int cvt_o(va_list ap, unsigned char flags[], int width, int precision);
int cvt_x(va_list ap, unsigned char flags[], int width, int precision);
int cvt_c(va_list ap, unsigned char flags[], int width, int precision);
int cvt_i(va_list ap, unsigned char flags[], int width, int precision);
int cvt_d(va_list ap, unsigned char flags[], int width, int precision);
int cvt_s(va_list ap, unsigned char flags[], int width, int precision);
int cvt_p(va_list ap, unsigned char flags[], int width, int precision);

/* write functions */
int _putchar(char c);
int _puts(char *str, unsigned char flags[], int width, int precision);
int _putd(char *str, unsigned char flags[], int width, int precision);
int pad(int n, char c);
void norm_width_and_flags(int *width, int *precision, unsigned char flags[]);
void compute_sign(char *str, int *len, int *sign, unsigned char flags[]);

/* format functions */
int vfmt(const char *format, va_list ap);
int _printf(const char *format, ...);
void get_flag(const char *fmt, unsigned char flags[]);
void get_precision(va_list ap, const char *fmt, int *prec);
void get_width(va_list ap, const char *fmt, int *width);

#endif /* #endif MAIN_H  */
