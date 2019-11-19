/*
** EPITECH PROJECT, 2022
** My rpg
** File description:
** Character's file
*/

#include "my.h"
#include "rpg.h"

void init_character(scene_t *game, int i)
{
	sfIntRect rect = {0, 0, 60, 60};

	rect.top += i;
	game->charac[0] = malloc(sizeof(charac_t));
	game->charac[0]->level = 1;
	game->charac[0]->life = 100;
	game->charac[0]->damage = 10;
	game->charac[0]->magic = 10;
	sfSprite_setTextureRect(game->sprite[2]->spr, rect);
}

void start_pnj(scene_t *game, int i)
{
	sfIntRect rect = {0, 0, 60, 60};

	rect.top += i;
	sfSprite_setTextureRect(game->sprite[3]->spr, rect);
	game->sprite[3]->type = PLAYER;
	game->charac[1] = malloc(sizeof(charac_t));
	game->charac[1]->life = 100000;
	game->charac[1]->damage = 0;
	game->charac[1]->magic = 0;
	game->charac[1]->pnj = malloc(sizeof(pnj_t));
	game->charac[1]->pnj->chat = 0;
	game->charac[1]->pnj->quest = 0;
	game->charac[1]->pnj->n_dialog = 0;
	game->charac[1]->pnj->n_dialog2 = 0;
	game->charac[1]->pnj->n_dialog3 = 0;
	game->charac[1]->pnj->dialog = malloc(sizeof(char **) * 4);
	game->charac[1]->pnj->dialog[0] = init_quests();
	game->charac[1]->pnj->dialog[1] = init_quests_home();
	game->charac[1]->pnj->dialog[2] = init_quests_overworld2();
	game->charac[1]->pnj->dialog[3] = NULL;
}

void init_pnj(scene_t *game, int i)
{
	sfIntRect rect = {0, 0, 60, 60};

	rect.top += i;
	sfSprite_setTextureRect(game->sprite[3]->spr, rect);
	game->sprite[3]->type = PLAYER;
}

void init_mob(scene_t *game)
{
	sfIntRect rect = {0, 0, 60, 60};

	game->sprite[1]->type = PLAYER;
	sfSprite_setTextureRect(game->sprite[1]->spr, rect);
	game->charac[2] = malloc(sizeof(charac_t));
	game->charac[2]->clock = sfClock_create();
	game->charac[2]->life = 1;
	game->charac[2]->damage = 10;
	game->charac[2]->magic = 0;
	game->sprite[1]->type = PLAYER;
}