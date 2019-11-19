/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** By Ndr
*/

#include "my.h"

long int get_maxdiv_nbr(int nbr)
{
	long int res = 10;
	long int mult = 1;

	while (res >= 10){
		res = nbr / mult;
		mult *= 10;
	}
	mult /= 10;
	return mult;
}

void my_put_nbr(int nbr)
{
	long int res = 0;
	long int div = 0;

	if (nbr < 0){
		my_putchar('-');
		nbr *= -1;
	}
	div = get_maxdiv_nbr(nbr);
	while (nbr > 0){
		res = nbr / div;
		my_putchar(res + '0');
		nbr -= div * res;
		div /= 10;
	}
	while (div >= 1 && nbr == 0){
		my_putchar('0');
		div /= 10;
	}
}
