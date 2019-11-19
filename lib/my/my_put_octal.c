/*
** EPITECH PROJECT, 2017
** my_put_octal
** File description:
** By Ndr
*/

#include "my.h"

long int get_maxdiv_oct(int oct)
{
	long int res = 8;
	long int mult = 1;

	while (res >= 8){
		res = oct / mult;
		mult *= 8;
	}
	mult /= 8;
	return mult;
}

void my_put_octal(int oct)
{
	long int res = 0;
	long int div = 0;

	if (oct < 0){
		my_putchar('-');
		oct *= -1;
	}
	div = get_maxdiv_oct(oct);
	while (oct > 0){
		res = oct / div;
		my_putchar(res + '0');
		oct -= div * res;
		div /= 8;
	}
	if (div == 1 && oct == 0){
		my_putchar('0');
	}
}
