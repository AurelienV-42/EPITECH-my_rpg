/*
** EPITECH PROJECT, 2017
** my.h - LibMy function's prototypes
** File description:
** By Ndr
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

//Retrieving values
int my_getnbr(char const *str);

int my_strlen(char const *str);

//Tests on strings
int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_isupper(char const *str);

int my_str_islower(char const *str);

int my_str_isprintable(char const *str);

//Prompting values
void my_putchar(char const c);

void my_putstr(char const *str);
void my_putstr_error(char const *str);

void my_put_nbr(int nbr);
long int get_maxdiv_nbr(int nbr);

int my_put_unsigned(unsigned int nb);
void my_put_unsigned2(unsigned int *nb, long *reverse, int *last, int *digit);

void my_put_allchar(char *str);
void print_special(char c);

void my_put_bin(unsigned int bin);
long int get_maxdiv_bin(unsigned int bin);

void my_put_hexa(int hex, int maj);
long int get_maxdiv_hex(int hex);

void my_put_octal(int oct);
long int get_maxdiv_oct(int oct);

void my_put_pointer(unsigned long int ptr);
long int get_maxdiv_ptr(unsigned long int ptr);

//Operations on strings
char *my_revstr(char *str);

char *my_strcat(char *dest, char const *src);

char *my_strdup(char const *src);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_score_str(int);

//Operations on pointers
void my_swap(int *a, int *b);

//Operations on 2D arrays
char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char *load_file_in_mem(char const *filepath);

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

void free_2d_char_array(char **ptr, int nb_rows);

////Libmy's programs
//my_printf
int my_printf(const char *str, ...);
int my_printr(const char *str, va_list ap);
void print_var(const char *str, int *i, va_list ap);
void print_var2(const char *str, int *i, va_list ap);
void print_var3(const char *str, int *i, va_list ap);
void print_var4(const char *str, int *i, va_list ap);

#endif /*! MY_H_*/
