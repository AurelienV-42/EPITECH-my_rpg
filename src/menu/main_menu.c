/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main menu
*/

#include "rpg.h"

static void load_main_menu(scene_t *menu)
{
	menu->sprite = malloc(sizeof(sprite_t *) * MENU_MAX_SPRITES);
	menu->button = malloc(sizeof(button_t *) * MENU_MAX_BUTTONS);
	menu->sounds = malloc(sizeof(sfMusic *) * MENU_MAX_AUDIO);
	menu->sprite[0] = create_sprite(MENU_BG_FILE, BG, 0, 0);
	menu->sprite[1] =
	create_sprite(MENU_LOGO_FILE, BG, MENU_LOGO_X, MENU_LOGO_Y);
	menu->button[0] = create_button(MENU_PLAY_BUTTON_FILE,
	MENU_BUTTON_SIZE_X, MENU_BUTTON_SIZE_Y, &play_button);
	move_button(menu->button[0], MENU_PLAY_BUTTON_X, MENU_BUTTON_Y);
	menu->button[1] = create_button(
	MENU_EXIT_BUTTON_FILE, MENU_HTP_SIZE_X, MENU_HTP_SIZE_Y, &exit_button);
	move_button(menu->button[1], MENU_EXIT_BUTTON_X, MENU_BUTTON_Y);
	menu->button[2] = create_button(
	MENU_HTP_BUTTON_FILE, MENU_HTP_SIZE_X, MENU_HTP_SIZE_Y, &htp_button);
	move_button(menu->button[2], MENU_HTP_BUTTON_X, MENU_BUTTON_Y);
	menu->sounds[0] = sfMusic_createFromFile(MENU_AUDIO_BACKGROUND);
	sfMusic_setLoop(menu->sounds[0], sfTrue);
	sfMusic_play(menu->sounds[0]);
}

static void display_main_menu(global_t *global, scene_t *menu)
{
	sfRenderWindow_clear(global->window, sfBlue);
	for (int i = 0; i < MENU_MAX_SPRITES; i++) {
		if (sfRenderWindow_isOpen(global->window))
			sfRenderWindow_drawSprite(
			global->window, menu->sprite[i]->spr, NULL);
	}
	for (int i = 0; i < MENU_MAX_BUTTONS; i++) {
		if (sfRenderWindow_isOpen(global->window))
			sfRenderWindow_drawSprite(
			global->window, menu->button[i]->spr, NULL);
	}
	sfRenderWindow_display(global->window);
}

static void destroy_main_menu(scene_t *menu)
{
	for (int i = 0; i < MENU_MAX_SPRITES; i++) {
		sfSprite_destroy(menu->sprite[i]->spr);
		sfTexture_destroy(menu->sprite[i]->tex);
		free(menu->sprite[i]);
	}
	for (int i = 0; i < MENU_MAX_BUTTONS; i++) {
		sfSprite_destroy(menu->button[i]->spr);
		sfTexture_destroy(menu->button[i]->tex);
		sfRectangleShape_destroy(menu->button[i]->rect);
		free(menu->button[i]);
	}
	for (int i = 0; i < MENU_MAX_AUDIO; i++) {
		sfMusic_stop(menu->sounds[0]);
		sfMusic_destroy(menu->sounds[i]);
	}
	free(menu->sprite);
	free(menu->button);
	free(menu->sounds);
}

void main_menu_main(global_t *global)
{
	static scene_t menu;

	switch (global->scene_state) {
	case LOAD:
		global->scene_state = LOADING;
		load_main_menu(&menu);
		global->scene_state = LOADED;
		break;
	case LOADED:
		display_main_menu(global, &menu);
		main_menu_events(global, &menu);
		break;
	case UNLOAD:
		global->scene_state = UNLOADING;
		destroy_main_menu(&menu);
		global->scene_state = UNLOADED;
		break;
	default:
		global->scene_state = ERROR;
		break;
	}
}
