/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Menu events handler
*/

#include "rpg.h"
#include "my.h"

void htp_next_button(
global_t *global __attribute__((unused)), scene_t *htp, int *page)
{
	if (*page < HTP_MAX_PAGES) {
		sfMusic_play(htp->sounds[1]);
		(*page)++;
	} else
		sfMusic_play(htp->sounds[2]);
}

void htp_prev_button(
global_t *global __attribute__((unused)), scene_t *htp, int *page)
{
	if (*page > 1) {
		sfMusic_play(htp->sounds[1]);
		(*page)--;
	} else
		sfMusic_play(htp->sounds[2]);
}

void htp_exit_button(global_t *global, scene_t *htp __attribute__((unused)),
int *page __attribute__((unused)))
{
	sfMusic_play(global->sounds[1]);
	global->scene_state = UNLOAD;
	global->next_scene = MAIN_MENU;
}

static void htp_click_handler(global_t *global, scene_t *htp, int *page)
{
	sfVector2i mo = sfMouse_getPositionRenderWindow(global->window);

	for (int i = 0; i < MENU_MAX_BUTTONS; i++)
		if (button_is_clicked(htp->button[i], mo))
			htp->button[i]->action(global, htp, page);
}

void htp_events(global_t *global, scene_t *htp, int *page)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(global->window, &event)) {
		if (event.type == sfEvtClosed
		|| sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
			global->scene_state = UNLOAD;
			global->next_scene = MAIN_MENU;
		}
		if (sfKeyboard_isKeyPressed(sfKeyLeft))
			htp_prev_button(global, htp, page);
		if (sfKeyboard_isKeyPressed(sfKeyRight))
			htp_next_button(global, htp, page);
		if (event.type == sfEvtMouseButtonPressed)
			htp_click_handler(global, htp, page);
	}
}