/*
** EPITECH PROJECT, 2017
** my_put_bin
** File description:
** By Ndr
*/

#include "my.h"

long int get_maxdiv_bin(unsigned int bin)
{
	long int res = 2;
	long int mult = 1;

	while (res >= 2){
		res = bin / mult;
		mult *= 2;
	}
	mult /= 2;
	return mult;
}

void my_put_bin(unsigned int bin)
{
	long int res = 0;
	long int div = 0;

	if (bin < 0){
		my_putchar('-');
		bin *= -1;
	}
	div = get_maxdiv_bin(bin);
	while (bin > 0){
		res = bin / div;
		my_putchar(res + '0');
		bin -= div * res;
		div /= 2;
	}
	for (div; div >= 1; div /= 2)
		my_putchar('0');
	if (div == 1 && bin == 0){
		my_putchar('0');
	}
}
