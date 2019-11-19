/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main game
*/

#include "my.h"
#include "rpg.h"

static void load_game(scene_t *game, global_t *global)
{
	game->sprite = malloc(sizeof(sprite_t *) * GAME_MAX_SPRITES);
	game->button = malloc(sizeof(button_t *) * GAME_MAX_BUTTONS);
	game->sounds = malloc(sizeof(sfMusic *) * GAME_MAX_AUDIO);
	game->charac = malloc(sizeof(charac_t *) * GAME_MAX_CHARAC);
	game->pause = 0;
	init_sounds(game);
	init_texts(game);
	map_switcher(0, game, global);
}

static void display_hud(global_t *global, scene_t *game)
{
	sfVector2f pos = {320, 200};
	sfVector2f pos2 = {320, 485};
	sfVector2f pos3 = {320, 340};
	sfVector2f pos4 = {320, 625};

	sfText_setPosition(game->text_hud, pos);
	sfText_setString(game->text_hud, my_score_str(game->charac[0]->level));
	sfRenderWindow_drawText(global->window, game->text_hud, NULL);
	sfText_setPosition(game->text_hud, pos3);
	sfText_setString(game->text_hud, my_score_str(game->charac[0]->life));
	sfRenderWindow_drawText(global->window, game->text_hud, NULL);
	sfText_setPosition(game->text_hud, pos2);
	sfText_setString(game->text_hud, my_score_str(game->charac[0]->magic));
	sfRenderWindow_drawText(global->window, game->text_hud, NULL);
	sfText_setPosition(game->text_hud, pos4);
	sfText_setString(game->text_hud, my_score_str(game->charac[0]->damage));
	sfRenderWindow_drawText(global->window, game->text_hud, NULL);
}

void display_game(global_t *global, scene_t *game)
{
	sfRenderWindow_clear(global->window, sfBlue);
	draw_tilemap(global, game);
	for (int i = 0; i < GAME_MAX_SPRITES - 1; i++)
		if (sfRenderWindow_isOpen(global->window)
		&& game->sprite[i]->type != FREE)
			sfRenderWindow_drawSprite(
			global->window, game->sprite[i]->spr, NULL);
	if (game->charac[1]->pnj->chat == 1) {
		sfRenderWindow_drawSprite(
		global->window, game->sprite[4]->spr, NULL);
		sfRenderWindow_drawText(global->window, game->text, NULL);
	}
	for (int i = 0; game->pause == 1 && i < GAME_MAX_BUTTONS; i++) {
		if (sfRenderWindow_isOpen(global->window))
			sfRenderWindow_drawSprite(
			global->window, game->button[i]->spr, NULL);
	}
	display_hud(global, game);
	sfRenderWindow_display(global->window);
}

static void destroy_game(scene_t *game)
{
	for (int i = 0; i < GAME_MAX_SPRITES; i++) {
		sfSprite_destroy(game->sprite[i]->spr);
		sfTexture_destroy(game->sprite[i]->tex);
		free(game->sprite[i]);
	}
	for (int i = 0; i < GAME_MAX_AUDIO; i++) {
		sfMusic_stop(game->sounds[i]);
		sfMusic_destroy(game->sounds[i]);
	}
	free(game->sprite);
	free(game->button);
	free(game->sounds);
	destroy_character(game);
	destroy_tilemap(game);
}

void game_main(global_t *global)
{
	static scene_t game;

	switch (global->scene_state) {
	case LOAD:
		global->scene_state = LOADING;
		load_game(&game, global);
		global->scene_state = LOADED;
		break;
	case LOADED:
		display_game(global, &game);
		game_events(global, &game);
		break;
	case UNLOAD:
		global->scene_state = UNLOADING;
		destroy_game(&game);
		global->scene_state = UNLOADED;
		break;
	default:
		global->scene_state = ERROR;
		break;
	}
}
