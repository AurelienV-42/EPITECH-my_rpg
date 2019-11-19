/*
** EPITECH PROJECT, 2017
** my_printf (printing part)
** File description:
** By Ndr
*/

#include "my.h"
#include <stdarg.h>

void print_var4(const char *str, int *i, va_list ap)
{
	switch (str[*i + 1]){
	case '\0':
		*i++;
		break;
	default:
		my_putchar('%');
		my_putchar(str[*i]);
		*i += 2;
		break;
	}
}

void print_var3(const char *str, int *i, va_list ap)
{
	switch (str[*i + 1]){
	case 'p':
		my_put_pointer(va_arg(ap, unsigned long int));
		break;
	case 'b':
		my_put_bin(va_arg(ap, unsigned int));
		*i++;
		break;
	case 'S':
		my_put_allchar(va_arg(ap, char *));
		break;
	case '%':
		my_putchar('%');
		*i++;
		break;
	default:
		print_var4(str, i, ap);
		break;
	}
}

void print_var2(const char *str, int *i, va_list ap)
{
	switch (str[*i + 1]){
	case 'o':
		my_put_octal(va_arg(ap, int));
		*i++;
		break;
	case 'x':
		my_put_hexa(va_arg(ap, int), 0);
		*i++;
		break;
	case 'X':
		my_put_hexa(va_arg(ap, int), 1);
		*i++;
		break;
	case 'u':
		my_put_unsigned(va_arg(ap, unsigned int));
		*i++;
		break;
	default:
		print_var3(str, i, ap);
		break;
	}
}

void print_var(const char *str, int *i, va_list ap)
{
	switch (str[*i + 1]){
	case 's':
		my_putstr(va_arg(ap, char *));
		*i++;
		break;
	case 'c':
		my_putchar(va_arg(ap, int));
		*i++;
		break;
	case 'i':
	case 'd':
		my_put_nbr(va_arg(ap, int));
		*i++;
		break;
	default:
		print_var2(str, i, ap);
		break;
	}
}
