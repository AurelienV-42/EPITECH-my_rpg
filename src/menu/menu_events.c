/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Menu events handler
*/

#include "rpg.h"

void exit_button(global_t *global)
{
	if (global->active_scene == MAIN_MENU) {
		global->scene_state = UNLOAD;
		global->next_scene = EXIT;
	}
}

void htp_button(global_t *global)
{
	if (global->active_scene == MAIN_MENU) {
		sfMusic_play(global->sounds[0]);
		global->scene_state = UNLOAD;
		global->next_scene = HOW_TO_PLAY;
	}
}

void play_button(global_t *global)
{
	if (global->active_scene == MAIN_MENU) {
		sfMusic_play(global->sounds[0]);
		global->scene_state = UNLOAD;
		global->next_scene = GAME;
	}
}

static void menu_click_handler(global_t *global, scene_t *menu)
{
	sfVector2i mo = sfMouse_getPositionRenderWindow(global->window);

	for (int i = 0; i < MENU_MAX_BUTTONS; i++)
		if (button_is_clicked(menu->button[i], mo))
			menu->button[i]->action(global, menu);
}

void main_menu_events(global_t *global, scene_t *menu)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(global->window, &event)) {
		if (event.type == sfEvtClosed
		|| sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
			exit_button(global);
		} else if (event.type == sfEvtMouseButtonPressed)
			menu_click_handler(global, menu);
	}
}