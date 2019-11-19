/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** By Ndr
*/

int my_str_isprintable(char const *str)
{
	int i;
	int success = 1;

	for (i = 0; str[i]; i++){
		if ((str[i] < 20) || (str[i] > 126))
			success = 0;
	}
	return success;
}
