/*
** EPITECH PROJECT, 2017
** Bootstrap BSQ - P3S2
** File description:
** By Ndr
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
	char **newtab = malloc(sizeof(char *) * nb_rows);

	for (int i = 0; i < nb_rows; i++)
		newtab[i] = malloc(sizeof(char) * nb_cols);
	return newtab;
}
