/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** By Ndr
*/

int my_getnbr(char const *str)
{
	int st, sign;
	int minus = 0;
	long long int nb = 0;
	int of_count = 0;

	for (st = 0; (str[st] < '0' || str[st] > '9') && str[st] != '\0'; st++);
	for (sign = st - 1; str[sign] == '+' || str[sign] == '-'; sign--)
		if (str[sign] == '-')
			minus++;
	for (st; str[st] >= '0' && str[st] <= '9' && str[st] != '\0'; st++){
		nb += str[st] - '0';
		nb *= 10;
		of_count++;
	}
	nb /= 10;
	if (minus % 2 == 1)
		nb *= -1;
	if (of_count > 11)
		return 0;
	return nb;
}
