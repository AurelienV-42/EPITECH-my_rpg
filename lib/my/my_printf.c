/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** By Ndr
*/

#include "my.h"
#include <stdarg.h>

int my_printr(const char *str, va_list ap)
{
	int len = my_strlen(str);
	int i = 0;
	int *pos = &i;

	for (i = 0; i < len; i++){
		if (str[i] != '%'){
			my_putchar(str[i]);
		}
		else{
			print_var(str, pos, ap);
			i++;
		}
	}
}

int my_printf(const char *str, ...)
{
	int var_nb = 0;
	int err = 0;
	va_list ap;

	va_start(ap, str);
	my_printr(str, ap);
	va_end(ap);
}
