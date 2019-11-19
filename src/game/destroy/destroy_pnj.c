/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Freeing character memory
*/

#include "my.h"
#include "rpg.h"

void destroy_pnj(scene_t *game)
{
	if (game->sprite[3]->spr != NULL)
		sfSprite_destroy(game->sprite[3]->spr);
	if (game->sprite[3]->tex != NULL)
		sfTexture_destroy(game->sprite[3]->tex);
	game->sprite[3]->type = FREE;
}