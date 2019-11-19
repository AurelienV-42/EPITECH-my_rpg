/*
** EPITECH PROJECT, 2017
** my_put_hexa
** File description:
** By Ndr
*/

#include "my.h"

long int get_maxdiv_hex(int hex)
{
	long int res = 16;
	long int mult = 1;

	while (res >= 16){
		res = hex / mult;
		mult *= 16;
	}
	mult /= 16;
	return mult;
}

void my_put_hexa(int hex, int maj)
{
	long int res = 0;
	long int div = 0;
	char *b = (maj == 0) ? "0123456789abcdef" : "0123456789ABCDEF";

	if (hex < 0){
		my_putchar('-');
		hex *= -1;
	}
	div = get_maxdiv_hex(hex);
	while (hex > 0){
		res = hex / div;
		my_putchar(b[res]);
		hex -= div * res;
		div /= 16;
	}
	if (div == 1 && hex == 0){
		my_putchar(b[0]);
	}
}
