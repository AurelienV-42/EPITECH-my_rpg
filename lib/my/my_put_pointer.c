/*
** EPITECH PROJECT, 2017
** my_put_pointer
** File description:
** By Ndr
*/

#include "my.h"

long int get_maxdiv_ptr(unsigned long int ptr)
{
	long int res = 16;
	long int mult = 1;

	while (res >= 16){
		res = ptr / mult;
		mult *= 16;
	}
	mult /= 16;
	return mult;
}

void my_put_pointer(unsigned long int ptr)
{
	char *b = "0123456789abcdef";
	long int res = 0;
	long int div = 0;

	if (ptr == 0){
		my_putstr("(nil)");
	}
	else{
		my_putstr("0x");
		div = get_maxdiv_ptr(ptr);
		while (ptr > 0){
			res = ptr / div;
			my_putchar(b[res]);
			ptr -= div * res;
			div /= 16;
		}
		if (div == 1 && ptr == 0){
			my_putchar(b[0]);
		}
	}
}
