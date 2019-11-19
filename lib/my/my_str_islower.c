/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** By Ndr
*/

int my_str_islower(char const *str)
{
	int i;
	int success = 1;

	for (i = 0; str[i]; i++){
		if ((str[i] < 'a') || (str[i] > 'z'))
			success = 0;
	}
	return success;
}
