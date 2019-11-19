/*
** EPITECH PROJECT, 2017
** free_2d_array
** File description:
** By Ndr
*/

#include <stdlib.h>

void free_2d_array(int **ptr, int nb_rows)
{
	for (int i = 0; i < nb_rows; i++)
		free(ptr[i]);
	free(ptr);
}
