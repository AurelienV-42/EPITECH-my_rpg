/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** File to leave the game
*/

#include "rpg.h"

static void create_buttons(scene_t *game)
{
	game->button[0] = create_button(GAME_PAUSE_RESUME_FILE,
	GAME_PAUSE_SIZEX, GAME_PAUSE_SIZEY, &do_nothing);
	move_button(game->button[0], GAME_PAUSE_RESUME_X, GAME_PAUSE_Y);
	game->button[1] = create_button(
	GAME_PAUSE_MENU_FILE, GAME_PAUSE_SIZEX, GAME_PAUSE_SIZEY, &do_nothing);
	move_button(game->button[1], GAME_PAUSE_MENU_X, GAME_PAUSE_Y);
	game->button[2] = create_button(
	GAME_PAUSE_QUIT_FILE, GAME_PAUSE_SIZEX, GAME_PAUSE_SIZEY, &do_nothing);
	move_button(game->button[2], GAME_PAUSE_QUIT_X, GAME_PAUSE_Y);
}

static void draw_pause(global_t *global, scene_t *game)
{
	sfVector2f pos = {GXO(0), GYO(13)};

	sfText_setString(game->text, QUIT);
	sfText_setPosition(game->text, pos);
	game->charac[1]->pnj->chat = 1;
	create_buttons(game);
	display_game(global, game);
	sfMusic_play(global->sounds[1]);
}

static void destroy_buttons(scene_t *game)
{
	for (int i = 0; i < GAME_MAX_BUTTONS; i++) {
		sfSprite_destroy(game->button[i]->spr);
		sfTexture_destroy(game->button[i]->tex);
		sfRectangleShape_destroy(game->button[i]->rect);
		free(game->button[i]);
	}
}

static int click_handler_pause(global_t *global, scene_t *game)
{
	sfVector2i mo = sfMouse_getPositionRenderWindow(global->window);

	if (button_is_clicked(game->button[1], mo)) {
		destroy_buttons(game);
		global->scene_state = UNLOAD;
		global->next_scene = MAIN_MENU;
		return 0;
	} else if (button_is_clicked(game->button[0], mo)) {
		destroy_buttons(game);
		game->charac[1]->pnj->chat = 0;
		return 0;
	}
	if (button_is_clicked(game->button[2], mo)) {
		destroy_buttons(game);
		global->scene_state = UNLOAD;
		global->next_scene = EXIT;
		return 0;
	}
	return 1;
}

void leave_the_game(global_t *global, scene_t *game)
{
	sfEvent event;

	game->pause = 1;
	draw_pause(global, game);
	while (
	sfRenderWindow_pollEvent(global->window, &event) || game->pause == 1) {
		if (event.type == sfEvtMouseButtonPressed)
			game->pause = click_handler_pause(global, game);
	}
}