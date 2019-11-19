/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Aurélien Vandaele <aurelien.vandaele@epitech.eu>
*/

#include "rpg.h"

void init_texts(scene_t *game)
{
	game->font = sfFont_createFromFile(FONT);
	game->text = sfText_create();
	game->text_hud = sfText_create();
	sfText_setFont(game->text, game->font);
	sfText_setFont(game->text_hud, game->font);
	sfText_setColor(game->text, sfBlack);
	sfText_setColor(game->text_hud, sfRed);
	sfText_setCharacterSize(game->text, 50);
	sfText_setCharacterSize(game->text_hud, 50);
}
