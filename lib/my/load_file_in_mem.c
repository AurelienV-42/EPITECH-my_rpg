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

char *load_file_in_mem(char const *filepath)
{
	struct stat fileinfo;
	int fd;
	char *str;
	int ret = 0;

	if (stat(filepath, &fileinfo) == -1)
		return NULL;
	str = malloc(fileinfo.st_size + 2);
	if (str == NULL)
		return NULL;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return NULL;
	ret = read(fd, str, fileinfo.st_size);
	if (ret != fileinfo.st_size)
		return NULL;
	str[fileinfo.st_size + 1] = '\0';
	close(fd);
	return str;
}
