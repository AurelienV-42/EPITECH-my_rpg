/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Aurélien Vandaele <aurelien.vandaele@epitech.eu>
*/

#include "rpg.h"

void init_sprite(scene_t *game)
{
	game->sprite[0] = create_sprite(GAME_MENU_BG_FILE, BG, 0, 0);
	game->sprite[1] =
	create_sprite(GAME_MOB, PLAYER, GXO(MOB_X), GYO(MOB_Y));
	game->sprite[2] = create_sprite(
	GAME_CHARACTER_FILE, PLAYER, GXO(CHARAC_X), GYO(CHARAC_Y));
	game->sprite[3] =
	create_sprite(GAME_PNJ_FILE, PLAYER, GXO(PNJ_X), GYO(PNJ_Y));
	game->map.collision[PNJ_Y][PNJ_X] = -1;
	game->sprite[4] = create_sprite(GAME_CHAT, BG, GXO(0), GYO(13));
}
