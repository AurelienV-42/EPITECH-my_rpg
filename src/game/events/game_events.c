/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game events handler
*/

#include "my.h"
#include "rpg.h"
#include <stdio.h>
#include <time.h>

void game_click_handler(global_t *global, scene_t *game)
{
	sfVector2i mo = sfMouse_getPositionRenderWindow(global->window);

	for (int i = 0; i < GAME_MAX_BUTTONS; i++)
		if (button_is_clicked(game->button[i], mo))
			game->button[i]->action(global, game);
}

static void no_interaction_pnj(scene_t *game)
{
	sfText_setString(game->text, NULL);
	game->charac[1]->pnj->chat = 0;
	if (game->charac[1]->pnj->quest == 0)
		game->charac[1]->pnj->n_dialog = 0;
}

static void interaction_pnj(scene_t *game, int i)
{
	sfIntRect rect = sfSprite_getTextureRect(game->sprite[2]->spr);

	if ((game->sprite[2]->pos.x == game->sprite[i]->pos.x + 60
	&& game->sprite[2]->pos.y == game->sprite[i]->pos.y
	&& rect.top == 60 * 3)
	|| (game->sprite[2]->pos.x == game->sprite[i]->pos.x
	&& game->sprite[2]->pos.y == game->sprite[i]->pos.y + 60
	&& rect.top == 0)
	|| (game->sprite[2]->pos.x == game->sprite[i]->pos.x
	&& game->sprite[2]->pos.y == game->sprite[i]->pos.y - 60
	&& rect.top == 60 * 2)
	|| (game->sprite[2]->pos.x == game->sprite[i]->pos.x - 60
	&& game->sprite[2]->pos.y == game->sprite[i]->pos.y
	&& rect.top == 61)) {
		if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue
		&& game->charac[1]->pnj->chat != -1)
			quest(game);
	} else
		no_interaction_pnj(game);
}

static void event_character(global_t *global, scene_t *game, sfIntRect *rect)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		(*rect).top = 0;
		if (is_a_collision(game, 2, 1) == 1)
			move_charac(game, 2, -1, global);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		(*rect).top = 60 * 2;
		if (is_a_collision(game, 2, 2) == 1)
			move_charac(game, 2, 1, global);
	} else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		(*rect).top = 60 * 3;
		if (is_a_collision(game, 2, 3) == 1)
			move_charac(game, 2, -2, global);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		(*rect).top = 61;
		if (is_a_collision(game, 2, 4) == 1)
			move_charac(game, 2, 2, global);
	}
	interaction_pnj(game, 3);
	sfSprite_setTextureRect(game->sprite[2]->spr, *rect);
}

void game_events(global_t *global, scene_t *game)
{
	sfEvent event;
	static sfIntRect rect = {0, 0, 60, 60};

	if (game->sprite[1]->type != FREE) {
		srand(time(NULL)
		+ sfClock_getElapsedTime(game->charac[2]->clock).microseconds);
	}
	while (sfRenderWindow_pollEvent(global->window, &event)) {
		if (event.type == sfEvtClosed
		|| sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			leave_the_game(global, game);
		change_quests(event, game);
		sfSprite_setTextureRect(game->sprite[2]->spr, rect);
	}
	event_character(global, game, &rect);
}
