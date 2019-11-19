/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Aurélien Vandaele <aurelien.vandaele@epitech.eu>
*/

#include "rpg.h"

static void quest_overworld2(scene_t *game)
{
	if (game->charac[1]->pnj->n_dialog3 < 1)
		sfText_setString(game->text,
		game->charac[1]
		->pnj->dialog[2][game->charac[1]->pnj->n_dialog3]);
	else {
		game->charac[1]->pnj->chat = -1;
		game->charac[1]->pnj->n_dialog3 = 0;
	}
}

static void quest_home(scene_t *game)
{
	if (game->charac[1]->pnj->quest != 0
	&& game->charac[1]->pnj->quest != -1) {
		if (game->charac[1]->pnj->n_dialog2 - 2 < NB_QUEST_PNJ_02) {
			sfText_setString(game->text,
			game->charac[1]
			->pnj->dialog[1][game->charac[1]->pnj->n_dialog2]);
			return;
		} else {
			game->charac[1]->pnj->quest = -1;
			game->charac[1]->pnj->n_dialog = 0;
		}
	}
	if (game->charac[1]->pnj->n_dialog2 < NB_TEXT_PNJ_02)
		sfText_setString(game->text,
		game->charac[1]
		->pnj->dialog[1][game->charac[1]->pnj->n_dialog2]);
	else {
		game->charac[1]->pnj->chat = -1;
		game->charac[1]->pnj->n_dialog2 = 0;
	}
}

static void quest_overworld(scene_t *game)
{
	if (game->charac[1]->pnj->quest == -1) {
		sfText_setString(
		game->text, game->charac[1]->pnj->dialog[0][8]);
		game->charac[1]->pnj->chat = 1;
		game->charac[0]->level = 2;
		game->charac[0]->damage = 50;
		return;
	}
	if (game->charac[1]->pnj->n_dialog < NB_TEXT_PNJ_01)
		sfText_setString(game->text,
		game->charac[1]
		->pnj->dialog[0][game->charac[1]->pnj->n_dialog]);
	else {
		game->charac[1]->pnj->chat = -1;
		game->charac[1]->pnj->quest++;
		game->charac[1]->pnj->n_dialog = 7;
		game->charac[1]->pnj->n_dialog2 = 2;
	}
}

void quest(scene_t *game)
{
	sfVector2f pos = {GXO(1), GYO(13)};

	sfText_setPosition(game->text, pos);
	game->charac[1]->pnj->chat = 1;
	switch (game->warp) {
	case 0:
	case 3:
		quest_overworld(game);
		break;
	case 1:
		quest_overworld2(game);
		break;
	case 2:
		quest_home(game);
		break;
	}
}

void change_quests(sfEvent event, scene_t *game)
{
	if (game->charac[1]->pnj->chat == 1 && event.type == sfEvtKeyReleased
	&& event.key.code == sfKeySpace)
		switch (game->warp) {
		case 0:
		case 3:
			game->charac[1]->pnj->n_dialog++;
			break;
		case 1:
			game->charac[1]->pnj->n_dialog3++;
			break;
		case 2:
			game->charac[1]->pnj->n_dialog2++;
			break;
		}
}