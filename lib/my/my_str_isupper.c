/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** By Ndr
*/

int my_str_isupper(char const *str)
{
	int i;
	int success = 1;

	for (i = 0; str[i]; i++){
		if ((str[i] < 'A') || (str[i] > 'Z'))
			success = 0;
	}
	return success;
}
