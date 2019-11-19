/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Made by Ndr
*/

#include <unistd.h>
#include "my.h"

void my_putstr_error(char const *str)
{
	write(2, str, my_strlen(str));
}
