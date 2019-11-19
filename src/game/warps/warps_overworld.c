/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Map warping functions
*/

#include "rpg.h"

void warp_overworld_left(scene_t *game, global_t *global)
{
	destroy_pnj(game);
	game->sprite[1]->type = FREE;
	game->sprite[3]->type = FREE;
	change_tilemap(
	game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_OVERWORLD2);
	game->sprite[2]->pos.x = GXO(1);
	game->sprite[2]->pos.y = GYO(7);
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	game->sprite[3] =
	create_sprite(GAME_PNJ_01_FILE, PLAYER, GXO(7), GYO(2));
	game->map.collision[2][7] = -1;
	init_pnj(game, 0);
	display_game(global, game);
}

void warp_overworld_two(scene_t *game, global_t *global)
{
	destroy_pnj(game);
	game->sprite[1]->type = FREE;
	game->sprite[3]->type = FREE;
	change_tilemap(
	game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_OVERWORLD2);
	game->sprite[2]->pos.x = GXO(3);
	game->sprite[2]->pos.y = GYO(15);
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	game->sprite[3] =
	create_sprite(GAME_PNJ_01_FILE, PLAYER, GXO(7), GYO(2));
	game->map.collision[2][7] = -1;
	init_pnj(game, 0);
	display_game(global, game);
}

void warp_overworld_up(scene_t *game, global_t *global)
{
	destroy_pnj(game);
	change_tilemap(
	game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_OVERWORLD);
	game->map.collision[PNJ_Y][PNJ_X] = -1;
	game->sprite[2]->pos.x = GXO(3);
	game->sprite[2]->pos.y = GYO(1);
	game->sprite[3] =
	create_sprite(GAME_PNJ_FILE, PLAYER, GXO(PNJ_X), GYO(PNJ_Y));
	game->sprite[1] =
	create_sprite(GAME_MOB, PLAYER, GXO(MOB_X), GYO(MOB_Y));
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	init_mob(game);
	init_pnj(game, 0);
	display_game(global, game);
}

void warp_overworld_house(scene_t *game, global_t *global)
{
	destroy_pnj(game);
	change_tilemap(
	game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_OVERWORLD);
	game->map.collision[PNJ_Y][PNJ_X] = -1;
	game->sprite[2]->pos.x = GXO(12);
	game->sprite[2]->pos.y = GYO(6);
	game->sprite[3] =
	create_sprite(GAME_PNJ_FILE, PLAYER, GXO(PNJ_X), GYO(PNJ_Y));
	game->sprite[1] =
	create_sprite(GAME_MOB, PLAYER, GXO(MOB_X), GYO(MOB_Y));
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	init_mob(game);
	init_pnj(game, 0);
	display_game(global, game);
}