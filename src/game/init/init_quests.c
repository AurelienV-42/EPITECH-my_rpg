/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Aurélien Vandaele <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include "rpg.h"

char **init_quests(void)
{
	char **text = malloc(sizeof(char *) * 10);

	text[0] = my_strdup(TEXT_PNJ_01);
	text[1] = my_strdup(TEXT_PNJ_02);
	text[2] = my_strdup(TEXT_PNJ_03);
	text[3] = my_strdup(TEXT_PNJ_04);
	text[4] = my_strdup(TEXT_PNJ_05);
	text[5] = my_strdup(TEXT_PNJ_06);
	text[6] = my_strdup(TEXT_PNJ_07);
	text[7] = my_strdup(TEXT_PNJ_08);
	text[8] = my_strdup(TEXT_PNJ_09);
	text[9] = NULL;
	return (text);
}

char **init_quests_home(void)
{
	char **text = malloc(sizeof(char *) * 6);

	text[0] = my_strdup(TEXT_PNJ_10);
	text[1] = my_strdup(TEXT_PNJ_11);
	text[2] = my_strdup(TEXT_PNJ_12);
	text[3] = my_strdup(TEXT_PNJ_13);
	text[4] = my_strdup(TEXT_PNJ_14);
	text[5] = NULL;
	return (text);
}

char **init_quests_overworld2(void)
{
	char **text = malloc(sizeof(char *) * 2);

	text[0] = my_strdup(TEXT_PNJ_15);
	text[1] = NULL;
	return (text);
}
