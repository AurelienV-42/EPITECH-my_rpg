/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** By Ndr
*/

int my_strlen(char const *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++){}
	return i;
}
