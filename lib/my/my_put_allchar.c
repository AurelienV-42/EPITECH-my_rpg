/*
** EPITECH PROJECT, 2017
** my_put_allchar
** File description:
** By Ndr
*/

#include "my.h"

void print_special(char c)
{
	my_putchar('\\');
	my_put_octal(c);
}

void my_put_allchar(char *str)
{
	int len = my_strlen(str);

	for (int i = 0; i < len; i++){
		if (str[i] < 32 || str[i] >= 127){
			print_special(str[i]);
		}
		else
			my_putchar(str[i]);
	}
}
