/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Map changer
*/

#include "rpg.h"
#include "my.h"

static void warp_init(scene_t *game)
{
	init_tilemap(game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_OVERWORLD);
	init_sprite(game);
	init_character(game, 60 * 3);
	start_pnj(game, 0);
	init_mob(game);
}

static void warp_bit(scene_t *game, global_t *global)
{
	game->sprite[1]->type = FREE;
	game->sprite[3]->type = FREE;
	change_tilemap(game, NB_TILES_TEST, TILES_TEST, MAP_TEST);
	game->sprite[2]->pos.x = GXO(0);
	game->sprite[2]->pos.y = GYO(0);
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	display_game(global, game);
}

static void warp_home(scene_t *game, global_t *global)
{
	destroy_pnj(game);
	game->sprite[1]->type = FREE;
	change_tilemap(game, NB_TILES_HOUSE, TILES_HOUSE, MAP_HOUSE);
	game->map.collision[7][9] = -1;
	game->sprite[2]->pos.x = GXO(6);
	game->sprite[2]->pos.y = GYO(10);
	game->sprite[3] =
	create_sprite(GAME_PNJ_01_FILE, PLAYER, GXO(9), GYO(7));
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	init_pnj(game, 0);
	display_game(global, game);
}

static void warp_bap(scene_t *game, global_t *global)
{
	game->sprite[1]->type = FREE;
	game->sprite[3]->type = FREE;
	change_tilemap(game, NB_TILES_OVERWORLD, TILES_OVERWORLD, MAP_BAP);
	game->sprite[2]->pos.x = GXO(14);
	game->sprite[2]->pos.y = GYO(8);
	sfSprite_setPosition(game->sprite[2]->spr, game->sprite[2]->pos);
	display_game(global, game);
}

void map_switcher(short warp, scene_t *game, global_t *global)
{
	short i = 0;
	warp_switch_t warp_list[] =
	{{0, &warp_init},
	{1, &warp_overworld_two},
	{2, &warp_home},
	{3, &warp_overworld_house},
	{4, &warp_overworld_up},
	{5, &warp_bap},
	{6, &warp_bit},
	{7, &warp_overworld_left},
	{-1, NULL}};

	for (; warp_list[i].warp != -1 && warp_list[i].warp != warp; i++);
	if (warp_list[i].warp == -1)
		my_printf("[E] Invalid warp %i\n", warp);
	else
		(warp_list[i].warp_function)(game, global, warp);
}