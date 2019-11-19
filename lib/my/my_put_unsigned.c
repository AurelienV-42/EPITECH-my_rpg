/*
** EPITECH PROJECT, 2017
** my_put_unsigned
** File description:
** By Ndr
*/

#include <unistd.h>
#include "my.h"

void my_put_unsigned2(unsigned int *nb, long *reverse, int *last, int *digit)
{
	if ((*nb) == 0){
		my_putchar('0');
		(*digit)--;
	}
	while ((*nb) != 0){
		(*reverse) = (*reverse) * 10;
		(*reverse) = (*reverse) + (*nb) % 10;
		(*nb) = (*nb) / 10;
	}
	while ((*reverse) > 0){
		(*last) = (*reverse) % 10;
		(*last) += 48;
		my_putchar(*last);
		(*digit)--;
		(*reverse) /= 10;
	}
	while ((*digit) > 0){
		my_putchar('0');
		(*digit)--;
	}
}

int my_put_unsigned(unsigned int nb)
{
	int last = 0;
	long reverse = 0;
	int digit = 0;
	unsigned int calclen;
	int *nbptr = &nb;
	long *revptr = &reverse;
	int *lastptr = &last;
	int *digitptr = &digit;

	if (nb < 0){
		my_putchar('-');
		nb = nb * -1;
	}
	calclen = nb;
	while (calclen >= 1){
		digit++;
		calclen = calclen / 10;
	}
	my_put_unsigned2(nbptr, revptr, lastptr, digitptr);
	return 0;
}
