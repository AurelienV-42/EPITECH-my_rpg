/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** By Ndr
*/

int my_str_isnum(char const *str)
{
	int i;
	int success = 1;

	for (i = 0; str[i]; i++)
		if ((str[i] < '0') || (str[i] > '9'))
			success = 0;
	return success;
}
