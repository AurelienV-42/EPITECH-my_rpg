/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Freeing character memory
*/

#include "my.h"
#include "rpg.h"

void destroy_mob(scene_t *game)
{
	if (game->sprite[1]->spr != NULL)
		sfSprite_destroy(game->sprite[1]->spr);
	if (game->sprite[1]->tex != NULL)
		sfTexture_destroy(game->sprite[1]->tex);
	if (game->charac[2] != NULL)
		free(game->charac[2]);
	game->sprite[1]->type = FREE;
}