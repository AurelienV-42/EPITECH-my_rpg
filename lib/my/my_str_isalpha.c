/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** By Ndr
*/

int my_str_isalpha(char const *str)
{
	int i;
	int success = 1;

	for (i = 0; str[i]; i++){
		if (((str[i] < 'A') || (str[i] > 'Z')) &&
		((str[i] < 'a') || (str[i] > 'z')))
			success = 0;
	}
	return success;
}
