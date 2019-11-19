/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** By Ndr
*/

char *my_revstr(char *str)
{
	int len = 0;
	int pos = 0;
	char tmp = 0;
	int limit;

	while (str[len] != '\0')
		len++;
	limit = len / 2;
	len--;
	while (len >= limit){
		tmp = str[len];
		str[len] = str[pos];
		str[pos] = tmp;
		pos++;
		len--;
	}
	return str;
}
