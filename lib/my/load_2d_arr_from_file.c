/*
** EPITECH PROJECT, 2017
** BSQ Bootstrap - P4S1
** File description:
** By Ndr
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
	char *file = load_file_in_mem(filepath);
	int pos = 0;
	char **arr;

	if (file == NULL)
		return NULL;
	arr = mem_alloc_2d_array(nb_rows, nb_cols);
	for (int i = 0; i < nb_rows; i++){
		for (int j = 0; j < nb_cols; j++){
			arr[i][j] = file[pos];
			pos++;
		}
		while (file[pos - 1] != '\n')
			pos++;
	}
	free(file);
	return arr;
}
