/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main menu
*/

#include "rpg.h"

static void htp_create_buttons(scene_t *htp)
{
	htp->button[0] = create_button(HTP_PREV_BUTTON_FILE, HTP_BUTTON_SIZE_X,
	HTP_BUTTON_SIZE_Y, &htp_prev_button);
	move_button(htp->button[0], HTP_PREV_BUTTON_X, HTP_BUTTON_Y);
	htp->button[1] = create_button(HTP_EXIT_BUTTON_FILE, HTP_BUTTON_SIZE_X,
	HTP_BUTTON_SIZE_Y, &htp_exit_button);
	move_button(htp->button[1], HTP_EXIT_BUTTON_X, HTP_BUTTON_Y);
	htp->button[2] = create_button(HTP_NEXT_BUTTON_FILE, HTP_BUTTON_SIZE_X,
	HTP_BUTTON_SIZE_Y, &htp_next_button);
	move_button(htp->button[2], HTP_NEXT_BUTTON_X, HTP_BUTTON_Y);
}

static void load_htp(scene_t *htp)
{
	htp->sprite = malloc(sizeof(sprite_t *) * HTP_MAX_SPRITES);
	htp->button = malloc(sizeof(button_t *) * HTP_MAX_BUTTONS);
	htp->sounds = malloc(sizeof(sfMusic *) * HTP_MAX_AUDIO);
	htp->sprite[0] = create_sprite(HTP_BG_FILE, BG, 0, 0);
	htp->sprite[1] =
	create_sprite(HTP_PAGE_1_FILE, BG, HTP_POSITION_X, HTP_POSITION_Y);
	htp->sprite[2] =
	create_sprite(HTP_PAGE_2_FILE, BG, HTP_POSITION_X, HTP_POSITION_Y);
	htp_create_buttons(htp);
	htp->sounds[0] = sfMusic_createFromFile(HTP_AUDIO_BACKGROUND);
	sfMusic_setLoop(htp->sounds[0], sfTrue);
	sfMusic_play(htp->sounds[0]);
	htp->sounds[1] = sfMusic_createFromFile(HTP_AUDIO_OK);
	htp->sounds[2] = sfMusic_createFromFile(HTP_AUDIO_NO);
}

static void display_htp(global_t *global, scene_t *htp, int *page)
{
	sfRenderWindow_clear(global->window, sfBlue);
	if (sfRenderWindow_isOpen(global->window)) {
		sfRenderWindow_drawSprite(
		global->window, htp->sprite[0]->spr, NULL);
		sfRenderWindow_drawSprite(
		global->window, htp->sprite[*page]->spr, NULL);
	}
	for (int i = 0; i < HTP_MAX_BUTTONS; i++) {
		if (sfRenderWindow_isOpen(global->window))
			sfRenderWindow_drawSprite(
			global->window, htp->button[i]->spr, NULL);
	}
	sfRenderWindow_display(global->window);
}

static void destroy_htp(scene_t *htp)
{
	for (int i = 0; i < HTP_MAX_SPRITES; i++) {
		sfSprite_destroy(htp->sprite[i]->spr);
		sfTexture_destroy(htp->sprite[i]->tex);
		free(htp->sprite[i]);
	}
	for (int i = 0; i < HTP_MAX_BUTTONS; i++) {
		sfSprite_destroy(htp->button[i]->spr);
		sfTexture_destroy(htp->button[i]->tex);
		sfRectangleShape_destroy(htp->button[i]->rect);
		free(htp->button[i]);
	}
	for (int i = 0; i < HTP_MAX_AUDIO; i++) {
		sfMusic_stop(htp->sounds[i]);
		sfMusic_destroy(htp->sounds[i]);
	}
	free(htp->sprite);
	free(htp->button);
	free(htp->sounds);
}

void main_htp(global_t *global)
{
	static scene_t htp;
	static int page = 1;

	switch (global->scene_state) {
	case LOAD:
		global->scene_state = LOADING;
		load_htp(&htp);
		global->scene_state = LOADED;
		break;
	case LOADED:
		display_htp(global, &htp, &page);
		htp_events(global, &htp, &page);
		break;
	case UNLOAD:
		global->scene_state = UNLOADING;
		destroy_htp(&htp);
		global->scene_state = UNLOADED;
		break;
	default:
		global->scene_state = ERROR;
	}
}
