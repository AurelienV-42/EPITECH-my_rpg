/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Aurélien Vandaele <aurelien.vandaele@epitech.eu>
*/

#include "rpg.h"

void init_sounds(scene_t *game)
{
	game->sounds[0] = sfMusic_createFromFile(GAME_AUDIO_BACKGROUND);
	sfMusic_setLoop(game->sounds[0], sfTrue);
	sfMusic_play(game->sounds[0]);
}
