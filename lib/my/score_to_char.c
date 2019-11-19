/*
** EPITECH PROJECT, 2018
** My Runner
** File description:
** By Ndr
*/

#include <stdlib.h>

long int get_maxdiv(int nbr)
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

char *my_score_str(int nbr)
{
	long int res = 0;
	long int div = 0;
	char *str = malloc(sizeof(char) * 10);
	int i = 0;

	div = get_maxdiv(nbr);
	while (nbr > 0){
		res = nbr / div;
		str[i] = res + '0';
		i++;
		nbr -= div * res;
		div /= 10;
	}
	while (div >= 1 && nbr == 0){
		str[i] = '0';
		i++;
		div /= 10;
	}
	str[i] = '\0';
	return str;
}
