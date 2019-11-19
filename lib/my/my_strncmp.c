/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** By Ndr
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i;

	for (i = 0; ((s1[i] != '\0') && (s1[i] == s2[i]) && (i < n)); i++){}
	return (s1[i] - s2[i]);
}
