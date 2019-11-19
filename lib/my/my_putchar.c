/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** By Ndr
*/

#include <unistd.h>

void my_putchar(char const c)
{
	write(1, &c, 1);
}
