/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Freeing character memory
*/

#include "my.h"
#include "rpg.h"

void destroy_character(scene_t *game)
{
	free(game->charac[0]);
}